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

#ifndef ANY_H_20170625
#define ANY_H_20170625

#if __has_include(<any>) && __cplusplus > 201402L
#include <any>
#elif __has_include(<experimental / any>) && __cplusplus > 201402L
#include <experimental/any>
#elif __has_include(<boost/any.hpp>)
#include <boost/any.hpp>
#else
#error "Found no implementation of 'any' class."
#endif

namespace universal_retriever
{
#if __has_include(<any>) && __cplusplus > 201402L
    using std::any;
    using std::any_cast;
    using std::bad_any_cast;
#elif __has_include(<experimental/any>) && __cplusplus > 201402L
    using std::experimental::any;
    using std::experimental::any_cast;
    using std::experimental::bad_any_cast;
#elif __has_include(<boost/any.hpp>)
    using boost::any;
    using boost::any_cast;
    using boost::bad_any_cast;
#endif

    inline bool has_value(const any& value)
    {
#if __has_include(<any>) && __cplusplus > 201402L
        return value.has_value();
#else
        return !value.empty();
#endif
    }
}

#endif // ANY_H_20170625
