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
 * @file Frontend.h
 * 
 * @brief Front-end API for the universal retriever
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 15, 2014, 8:41 PM
 */
#ifndef FRONTEND_H_20141215
#define	FRONTEND_H_20141215

#include <BackendInterface.h>

#include <boost/any.hpp>
#include <boost/type_index.hpp>

#include <map>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief This is where the library lives ;-)
 */
namespace universal_retriever {

class HandlerInfo;

/**
 * @brief Class used in clients to retrieve persistent objects
 */
class Frontend {
public:
  using HandlerType = std::shared_ptr<BackendInterface>;

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
    return boost::any_cast<T>(retrieve(name, key, boost::typeindex::type_id<T>()));
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
   * Throws if the handler is unknown.
   * 
   * @param[in] info information on the handler to be added
   */
  void add_retrieve_handler(const HandlerInfo& info);

  /**
   * @brief Detach a retrieve handler from the front-end object
   * 
   * Throws if the handler is not attached.
   * 
   * @param[in] info information on the handler to be added         
   */
  void remove_retrieve_handler(const HandlerInfo& info);

  /**
   * @brief Attach a store handler to the front-end object
   * 
   * Only one store handler object may be associated with a given name.
   * Setting an handler for a name when one is already in use will
   * substitute the handler. Throws if the handler is unknown.
   * 
   * @param[in] info information on the handler to be added
   */
  void set_store_handler(const HandlerInfo& info);

  /**
   * @brief Detach the store handler associated with the given name
   * 
   * @param[in] name
   */
  void unset_store_handler(const std::string& name);

private:

  boost::any retrieve(const std::string& name, const std::string& key, const boost::typeindex::type_index& tid);
  
  std::map< std::string, std::vector<HandlerType> > m_retriever_map;
};

}

#endif	/* FRONTEND_H_20141215 */

