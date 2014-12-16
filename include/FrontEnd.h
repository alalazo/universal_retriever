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
 * @file FrontEnd.h
 * 
 * @brief Front-end API for the universal retriever
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 15, 2014, 8:41 PM
 */
#ifndef FRONTEND_H_20141215
#define	FRONTEND_H_20141215

#include <BackEndInterface.h>

#include <string>

/**
 * @brief This is where the library lives ;-)
 */
namespace universal_retriever {
            
    /**
     * @brief Class used in clients to retrieve persistent objects
     */
    class FrontEnd {
    public:
        /**
         * @brief Retrieves an object of type T 
         * 
         * @param[in] name identifies a set of registered handlers
         * @param[in] key key to search for in the selected handlers
         * 
         * @return required object or throws
         */
        template<class T>
        T retrieve(const std::string& name, const std::string& key);
        
        /**
         * @brief Stores an object of type T
         * 
         * @param[in] name identifies one particular handler
         * @param[in] key key associated with the value
         * @param[in] value value to be stored
         */
        template<class T>
        void store(const std::string& name, const std::string& key, const T& value);
        
        /**
         * @brief Forces serialization of the stored objects
         * 
         * @param[in] name identifies one particular handler
         */
        void serialize(const std::string& name);       
    };
    
}

#endif	/* FRONTEND_H_20141215 */

