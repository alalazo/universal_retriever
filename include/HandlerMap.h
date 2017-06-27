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
 * @file HandlerMap.h
 *
 * @brief Map to store registered plug-ins
 *
 * @author Massimiliano Culpo
 *
 * Created on December 17, 2014, 9:17 PM
 */

#ifndef HANDLERMAP_H_20141217
#define HANDLERMAP_H_20141217

#include <BackendInterface.h>
#include <HandlerInfo.h>

#include <map>
#include <memory>

namespace universal_retriever
{
    namespace details
    {

        class HandlerMap
        {
          public:
            using BackendType = std::shared_ptr<BackendInterface>;
            using MapType = std::map<HandlerInfo, BackendType>;

            static MapType& get();
        };
    }
}

#endif /* HANDLERMAP_H_20141217 */
