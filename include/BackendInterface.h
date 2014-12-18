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
 * @file BackendInterface.h
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

#include <memory>

namespace universal_retriever {

/**
 * @brief API for a back-end library to communicate with the front-end
 */
class BackendInterface {
public:

  /**
   * @brief Retrieves an object and packages it in a universal container
   * 
   * @param[in] key key associated with the object
   * 
   * @return universal container
   */
  virtual boost::any retrieve(const std::string& key) = 0;

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
  virtual ~BackendInterface();
};

/**
 * @brief Implementation details that should not be exposed to the public,
 * but need to stay in an header file
 */
namespace details {
bool register_backend(std::shared_ptr<BackendInterface> backend);
}

#define REGISTRABLE_BACKEND static bool m_is_registered
#define REGISTER_BACKEND( X ) bool X::m_is_registered( universal_retriever::details::register_backend(std::make_shared<X>()) )
}

#endif	/* BACKENDINTERFACE_H_20141215 */

