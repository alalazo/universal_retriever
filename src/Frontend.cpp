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

namespace universal_retriever {

boost::any Frontend::retrieve(const std::string& name, const std::string& key, const boost::typeindex::type_index& tid)
{
  auto & handler = m_retriever_map.at(name);
  return handler[0]->retrieve(key);
}

void Frontend::add_retrieve_handler(const HandlerInfo& info)
{
  auto& map = details::HandlerMap::get();
  auto handler = map.at(info); /// @todo may throw if info not present
  m_retriever_map[info.name()].push_back(handler);
}

}