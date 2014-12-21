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
 * @file BackendInterface.cpp
 * @brief Implementation for BackEndInterface.h
 * @author Massimiliano Culpo
 */

#include <BackendInterface.h>

#include <HandlerMap.h>
#include <UniversalRetrieverExceptions.h>

#include <sstream>

using namespace std;

namespace universal_retriever {

boost::any BackendInterface::retrieve(const std::string& key)
{
  return boost::any();
}

void BackendInterface::store(const std::string& key, const boost::any& value)
{
  stringstream estream;
  estream << "ERROR : the store cannot be performed as " << __func__ << "was not overridden" << endl;
  throw UnableToStore( estream.str() );
}

BackendInterface::~BackendInterface()
{
}

void BackendInterface::serialize()
{
}

namespace details {

bool register_backend(std::shared_ptr<BackendInterface> backend)
{
  auto & map=details::HandlerMap::get();
  auto item=make_pair(backend->info(), backend);
  return map.insert(item).second;
}

}
}