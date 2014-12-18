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
 * @file UniversalRetrieverExceptions.h
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 18, 2014, 8:58 PM
 */

#ifndef UNIVERSALRETRIEVEREXCEPTIONS_H_20141218
#define	UNIVERSALRETRIEVEREXCEPTIONS_H_20141218

#include <stdexcept>

namespace universal_retriever {

/**
 * @brief Exception thrown if an handler is not found in a query
 */
class HandlerNotFound : public std::out_of_range { 
  using std::out_of_range::out_of_range;
};

}

#endif	/* UNIVERSALRETRIEVEREXCEPTIONS_H_20141218 */

