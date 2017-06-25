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

#ifndef UNIVERSALRETRIEVER_ANY_H_20170625
#define UNIVERSALRETRIEVER_ANY_H_20170625

#include <experimental/any>

namespace universal_retriever {
    using std::experimental::any;
    using std::experimental::any_cast;
    using std::experimental::bad_any_cast;
}


#endif //UNIVERSALRETRIEVER_ANY_H_20170625
