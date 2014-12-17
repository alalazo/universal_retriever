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
 * @file BackEndInterface.h
 * 
 * @brief Back-end API for the universal retriever
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 15, 2014, 9:00 PM
 */

#ifndef BACKENDINTERFACE_H_20141215
#define	BACKENDINTERFACE_H_20141215

#include <HandlerInfo.h>

#include <boost/any.hpp>

namespace universal_retriever {
        
    /**
     * @brief API for a back-end library to communicate with the front-end
     */
    class BackEndInterface {
    public:
        
        /**
         * @brief Retrieves an object and packages it in a universal container
         * 
         * @param[in] key key associated with the object
         * 
         * @return universal container
         */
        virtual boost::any retrieve(const std::string& key);
        
        /**
         * @brief Stores an object with a given key
         * 
         * @param[in] key key associated with the object
         * @param[in] value object to be stored
         */
        virtual void store(const std::string& key, const boost::any& value);
        
        /**
         * @brief Triggers serialization of all the stored objects
         */
        virtual void serialize();
                
        /**
         * @brief Returns information on the handler
         */
        virtual HandlerInfo info() = 0;
        
        /**
         * @brief The infamous virtual destructor
         */
        virtual ~BackEndInterface() {
        }
    };
    
}

#endif	/* BACKENDINTERFACE_H_20141215 */

