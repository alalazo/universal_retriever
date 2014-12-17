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
 * @file HandlerInfo.h
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 17, 2014, 5:53 AM
 */

#ifndef HANDLERINFO_H_20141217
#define	HANDLERINFO_H_20141217

#include <string>

namespace universal_retriever {

    /**
     * @brief Provides information on a specific handler
     * 
     */
    class HandlerInfo {
    public:
        
        /**
         * @brief Constructs an HandlerInfo object
         * 
         * @param[in] name name of the handler
         * @param[in] version version of the handler
         * @param[in] method serialization method of the handler
         */
        HandlerInfo(
                const std::string & name,
                const std::string & version,
                const std::string & method) :
        m_name(name), m_version(version), m_method(method) {}
        
        /**
         * @brief Name associated with the handler
         */
        std::string name() const {
            return m_name;
        }

        /**
         * @brief Version of the handler
         */
        std::string version() const {
            return m_version;
        }

        /**
         * @brief Serialization method
         */
        std::string serialization_method() const {
            return m_method;
        }
    
    private:
        std::string m_name;
        std::string m_version;
        std::string m_method;        
    };

}

#endif	/* HANDLERINFO_H_20141217 */

