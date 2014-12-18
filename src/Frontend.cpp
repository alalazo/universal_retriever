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

#include <UniversalRetrieverExceptions.h>
#include <HandlerMap.h>

#include <algorithm>
#include <sstream>

using namespace std;

namespace universal_retriever {

boost::any Frontend::retrieve(const std::string& name, const std::string& key, const boost::typeindex::type_index& tid)
{
  // Cycle through all the handlers
  auto & handler = m_retriever_map.at(name);
  return handler[0]->retrieve(key);
}

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
    stringstream estream;
    estream << "Error in " << __func__ << " : handler is not registered in the engine" << endl;
    estream << info << endl;
    throw HandlerNotFound(estream.str());
  }
}

void Frontend::remove_retrieve_handler(const HandlerInfo& info)
{
  try
  {
    auto& hvector = m_retriever_map.at(info.name());
    hvector.erase(
                  remove_if(hvector.begin(), hvector.end(), [&info](HandlerType & x)
                  {
                    return x->info() == info;
                  }),
                  hvector.end()
                  );
  }
  catch (exception)
  {
    stringstream estream;
    estream << "Error in " << __func__ << " : handler was not added to the front-end" << endl;
    estream << info << endl;
    throw HandlerNotFound(estream.str());
  }
}

}