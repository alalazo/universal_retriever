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
 * @file simple_backend.cpp
 * 
 * @brief Tests a back-end that provides data from memory
 *
 * @author Massimiliano Culpo
 */

#include <FrontEnd.h>

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>

BOOST_AUTO_TEST_SUITE(SimpleBackendTest)
BOOST_AUTO_TEST_CASE(CommonOperations)
{
  using namespace universal_retriever;
  FrontEnd handler;
  
  auto a = handler.retrieve<int>("simple_backend","integer");
  
  BOOST_CHECK_EQUAL(a,0);
}        
BOOST_AUTO_TEST_SUITE_END()    