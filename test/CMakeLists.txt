#
# Universal Retriever : flexible engine for the retrieval of persistent objects
#
# Copyright (C) 2014  Massimiliano Culpo
#
# Universal Retriever is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Universal Retriever is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

FIND_PACKAGE( Boost 1.56 REQUIRED COMPONENTS unit_test_framework )

SET( TEST_SOURCES simple_backend_test.cpp )

##########
## Test libraries
ADD_LIBRARY( simple_backend SimpleBackend.cpp )
## Include directories
TARGET_INCLUDE_DIRECTORIES(
  simple_backend
  PUBLIC ${PROJECT_SOURCE_DIR}/test
)
## Link
TARGET_LINK_LIBRARIES(
  simple_backend
  PUBLIC  
  universal_retriever
)

##########

##########
## Dynamic library : collection of tests
ADD_LIBRARY( universal_retriever_tests ${TEST_SOURCES})
## Compile definitions
TARGET_COMPILE_DEFINITIONS(
  universal_retriever_tests
  PUBLIC BOOST_TEST_DYN_LINK
)
## Include directories
TARGET_INCLUDE_DIRECTORIES(
  universal_retriever_tests
  PUBLIC ${PROJECT_SOURCE_DIR}/test
)
## Link
TARGET_LINK_LIBRARIES(
  universal_retriever_tests
  PUBLIC  
  simple_backend
  universal_retriever
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
##########

##########
## Executable : dumb runner that triggers the tests that are dynamically linked
ADD_EXECUTABLE( test_universal_retriever.x test_main.cpp )
TARGET_LINK_LIBRARIES(
  test_universal_retriever.x
  universal_retriever_tests
)
##########
ADD_TEST(run_unit_test test_universal_retriever.x )
