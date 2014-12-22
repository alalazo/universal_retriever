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

SET(
  UNIVERSAL_RETRIEVER_SOURCES
  BackendInterface.cpp
  Frontend.cpp
  HandlerMap.cpp
)
## Library
ADD_LIBRARY( 
  universal_retriever SHARED 
  ${UNIVERSAL_RETRIEVER_HEADERS} 
  ${UNIVERSAL_RETRIEVER_SOURCES} 
)
## Set properties
SET_TARGET_PROPERTIES(
  universal_retriever
  PROPERTIES
  VERSION ${UniversalRetriever_VERSION}
  SOVERSION ${UniversalRetrieverAPI}
)
## Include directories
TARGET_INCLUDE_DIRECTORIES(
  universal_retriever
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
TARGET_INCLUDE_DIRECTORIES(
  universal_retriever
  SYSTEM 
  PUBLIC ${Boost_INCLUDE_DIRS}
)
## Installation
INSTALL(
  TARGETS universal_retriever
  EXPORT universal_retriever
  DESTINATION "lib"
)
INSTALL(
  EXPORT universal_retriever
  DESTINATION "cmake"
)