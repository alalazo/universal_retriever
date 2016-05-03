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

FIND_PACKAGE( Boost 1.55 REQUIRED COMPONENTS unit_test_framework )

SET(
  TEST_SOURCES
  simple_backend_test.cpp
  SimpleBackend.h
  SimpleBackend.cpp
)

##########
## Executable : dumb runner that triggers the tests that are dynamically linked
ADD_EXECUTABLE(
  test_universal_retriever
  test_main.cpp
  ${TEST_SOURCES}
)
target_compile_definitions(
  test_universal_retriever
  PUBLIC
  -DBOOST_ALL_DYN_LINK
)

TARGET_INCLUDE_DIRECTORIES(
  test_universal_retriever
  PUBLIC
  ${PROJECT_SOURCE_DIR}/test
)
TARGET_INCLUDE_DIRECTORIES(
  test_universal_retriever
  PUBLIC
  SYSTEM
  ${Boost_INCLUDE_DIRS}
)
TARGET_LINK_LIBRARIES(
  test_universal_retriever
  universal_retriever
  ${Boost_LIBRARIES}
)
SET_TARGET_PROPERTIES(
  test_universal_retriever
  PROPERTIES
  FOLDER test
)
##########
ADD_TEST(
  NAME run_unit_test
  COMMAND test_universal_retriever --report_level=detailed --build_info --log_format=xml --log_level=all --output_format=hrf --random --log_sink=test.log
)