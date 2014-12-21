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
 * @file simple_backend_test.cpp
 * 
 * @brief Tests a back-end that provides data from memory
 *
 * @author Massimiliano Culpo
 */

#include <Frontend.h>
#include <SimpleBackend.h>
#include <UniversalRetrieverExceptions.h>

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>

BOOST_AUTO_TEST_SUITE(SimpleBackendTest)
BOOST_AUTO_TEST_CASE(CommonOperations)
{
  using namespace universal_retriever;
  Frontend client;
  // Add an handler
  client.add_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") );
  // Retrieve a value
  auto a = client.retrieve<int>("simple_backend","integer");
  BOOST_CHECK_EQUAL(a,10);
  // Set store vector
  client.set_store_handler( HandlerInfo("simple_backend","1.0","memory") );
  // Store a value
  a = 20;
  client.store("simple_backend","integer",a);
  // Remove the retrieve handler
  client.remove_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") );
}        
BOOST_AUTO_TEST_CASE(Exceptions)
{
  using namespace universal_retriever;
  Frontend client;  
  BOOST_CHECK_THROW( client.add_retrieve_handler( HandlerInfo("invalid","1.0","invalid") ), HandlerNotFound );
  // Should add only one handler of the same type
  client.add_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") );
  client.add_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") );
  // Requires a non existing name
  BOOST_CHECK_THROW( client.retrieve<int>("invalid","integer"), HandlerNotFound );
  // Requires a non existing key
  BOOST_CHECK_THROW( client.retrieve<int>("simple_backend","intege"), KeyNotFound );  
  // Requires a wrong cast
  BOOST_CHECK_THROW( client.retrieve<double>("simple_backend","integer"), KeyTypeMismatch );
  // Try to remove a non existent handler  
  client.remove_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") );
  BOOST_CHECK_THROW( client.remove_retrieve_handler( HandlerInfo("simple_backend","1.0","memory") ), HandlerNotFound );  
}
BOOST_AUTO_TEST_SUITE_END()    