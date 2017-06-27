/*
 *  Universal Retriever : flexible engine for the retrieval of persistent objects
 *
 *  Copyright (C) 2014  Massimiliano Culpo
 *
 *  Universal Retriever is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Universal Retriever is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file Frontend.cpp
 * @brief Implementation for FrontEnd.h
 * @author Massimiliano Culpo
 */

#include <Frontend.h>

#include <HandlerMap.h>

#include <algorithm>

using namespace std;

#define HANDLER_NOT_IN_MAP(info)                                                                                       \
    stringstream estream;                                                                                              \
    estream << "ERROR (" << __func__ << ") : handler is not registered in the engine" << endl;                         \
    estream << info << endl;                                                                                           \
    throw HandlerNotFound(estream.str())

namespace universal_retriever
{

    //
    // Public
    //

    void Frontend::add_retrieve_handler(const HandlerInfo& info)
    {
        auto& map = details::HandlerMap::get();
        try
        {
            auto handler = map.at(info);
            auto& hvector = m_retriever_map[info.name()];
            // Push back handler if not present
            auto it = find(hvector.begin(), hvector.end(), handler);
            if (it == hvector.end())
            {
                hvector.push_back(handler);
            }
        }
        catch (out_of_range& e)
        {
            HANDLER_NOT_IN_MAP(info);
        }
    }

    void Frontend::remove_retrieve_handler(const HandlerInfo& info)
    {
        try
        {
            auto& hvector = m_retriever_map.at(info.name());

            auto mid = remove_if(hvector.begin(), hvector.end(), [&info](HandlerType& x) { return x->info() == info; });
            hvector.erase(mid, hvector.end());

            if (hvector.empty())
            {
                m_retriever_map.erase(info.name());
            }
        }
        catch (out_of_range& e)
        {
            stringstream estream;
            estream << "ERROR (" << __func__ << ") : retrieve handler was not added to the front-end" << endl;
            estream << info << endl;
            throw HandlerNotFound(estream.str());
        }
    }

    void Frontend::set_store_handler(const HandlerInfo& info)
    {
        auto& map = details::HandlerMap::get();

        try
        {
            auto handler = map.at(info);
            m_store_map[info.name()] = handler;
        }
        catch (out_of_range& e)
        {
            HANDLER_NOT_IN_MAP(info);
        }
    }

    void Frontend::unset_store_handler(const std::string& name) { m_store_map.erase(name); }

    void Frontend::serialize()
    {
        for (auto& x : m_store_map)
        {
            x.second->serialize();
        }
    }

    void Frontend::serialize(const std::string& name)
    {
        try
        {
            auto& handler = m_store_map.at(name);
            handler->serialize();
        }
        catch (out_of_range& e)
        {
            stringstream estream;
            estream << "ERROR (" << __func__ << R"() : there is no store handler for data type ")" << name << R"(")"
                    << endl;
            estream << "\tDid you forget to call set_store_handler and register the handler?" << endl;
            throw HandlerNotFound(estream.str());
        }
    }

    //
    // Private
    //

    universal_retriever::any Frontend::any_retrieve(const std::string& name, const std::string& key)
    {
        try
        {
            auto& hvector = m_retriever_map.at(name);
            return any_retrieve_from_hvector(hvector, key);
        }
        catch (out_of_range& e)
        {
            stringstream estream;
            estream << R"(ERROR : the front-end doesn't know how to manage ")" << name << R"(" data types)" << endl;
            estream << "\tDid you forget to call add_retrieve_handler and register the handler?" << endl;
            throw HandlerNotFound(estream.str());
        }
    }

    universal_retriever::any Frontend::any_retrieve_from_hvector(std::vector<HandlerType>& hvector,
                                                                 const std::string& key)
    {
        for (auto& x : hvector)
        {
            auto value = x->retrieve(key);
            if (has_value(value))
                return value;
        }
        // If the function did not return, then throw an exception
        stringstream estream;
        estream << R"(ERROR : key ")" << key << R"(" not managed by the following handlers : )" << endl;
        for (auto& x : hvector)
        {
            estream << x->info() << endl;
        }
        throw KeyNotFound(estream.str());
    }
}
