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
 * @file SimpleBackend.cpp
 * 
 * @brief Implementation for SimpleBackend.h
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 17, 2014, 8:07 PM
 */

#include <SimpleBackend.h>

using namespace std;

namespace universal_retriever {

universal_retriever::any SimpleBackEnd::retrieve(const std::string& key)
{
  if (key == "integer")
  {
    return m_integer;
  }
  else if (key == "double")
  {
    return m_double;
  }
  return universal_retriever::any();
}

HandlerInfo SimpleBackEnd::info()
{
  return HandlerInfo("simple_backend", "1.0", "memory");
}

void SimpleBackEnd::store(const std::string& key, const universal_retriever::any& value)
{
  if (key == "integer")
  {
    m_integer = universal_retriever::any_cast<int>(value);
  }
  else if (key == "double")
  {
    m_double = universal_retriever::any_cast<double>(value);
  }
  else
  {
    throw std::runtime_error("SimpleBackend::store : invalid key");
  }
}

REGISTER_BACKEND(SimpleBackEnd);
}