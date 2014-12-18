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
 * @file SimpleBackend.h
 * 
 * @brief A simple back-end for unit test purposes
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 17, 2014, 8:07 PM
 */

#ifndef SIMPLE_BACKEND_H_20141217
#define	SIMPLE_BACKEND_H_20141217

#include <BackendInterface.h>

namespace universal_retriever {

class SimpleBackEnd : public BackendInterface {
public:

  boost::any retrieve(const std::string& key) final;

  HandlerInfo info() final;

  void serialize() final;

  void store(const std::string& key, const boost::any& value) final;

private:
  int m_integer = 10;
  double m_double = 0.0;
  
  REGISTRABLE_BACKEND;
};

}

#endif	/* SIMPLE_BACKEND_H_20141217 */

