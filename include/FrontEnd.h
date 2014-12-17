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

#include <boost/any.hpp>
#include <boost/type_index.hpp>

#include <memory>
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
        using HandlerType = std::shared_ptr<BackEndInterface>;
        
        /**
         * @brief Retrieves an object of type T 
         * 
         * @param[in] name identifies a set of registered handlers
         * @param[in] key key to search for in the selected handlers
         * 
         * @return required object or throws
         */
        template<class T>
        T retrieve(const std::string& name, const std::string& key) {
            return boost::any_cast<T>( retrieve(name,key,boost::typeindex::type_id<T>() ) );
        }
        
        /**
         * @brief Stores an object of type T
         * 
         * @param[in] name identifies one particular store handler
         * @param[in] key key associated with the value
         * @param[in] value value to be stored
         */
        template<class T>
        void store(const std::string& name, const std::string& key, const T& value);
        
        /**
         * @brief Forces serialization of the stored objects
         * 
         * @param[in] name identifies one particular store handler
         */
        void serialize(const std::string& name);
        
        /**
         * @brief Attach a retrieve handler to the front-end object
         * 
         * More than one handler associated with the same name may be added.
         * The priority of use will be the same as the order of registration.
         * 
         * @param[in] name 
         */
        void add_retrieve_handler(const std::string& name);                
        
        /**
         * @brief 
         */
        void remove_retrieve_handler(const std::string& name);
        
        /**
         * @brief Attach a store handler to the front-end object
         * 
         * Only one store handler object may be associated with a given name.
         * Setting an handler for a name when one is already in use will
         * substitute the handler
         * 
         * @param[in] handler object implementing the back-end interface
         */
        void set_store_handler(HandlerType handler);
    private:
        
        boost::any retrieve(const std::string& name, const std::string& key, const boost::typeindex::type_index& tid) {
            return boost::any(1);
        }
    };
    
}

#endif	/* FRONTEND_H_20141215 */

