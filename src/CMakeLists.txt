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

find_package( Boost 1.55 REQUIRED )

add_library(universal_retriever
    SHARED
    ${UNIVERSAL_RETRIEVER_HEADERS}
        BackendInterface.cpp
        Frontend.cpp
        HandlerMap.cpp
)

set_warning_flags(universal_retriever)
set_rpath(universal_retriever)

set_target_properties(universal_retriever
    PROPERTIES
        VERSION ${UniversalRetriever_VERSION}
        SOVERSION ${UniversalRetrieverAPI}
        FOLDER lib
)


target_include_directories(universal_retriever
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

target_include_directories(universal_retriever
    SYSTEM PUBLIC
        ${Boost_INCLUDE_DIRS}
)

## Installation

install(TARGETS universal_retriever EXPORT UniversalRetrieverTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

install(
    EXPORT UniversalRetrieverTargets
    DESTINATION share/cmake
)