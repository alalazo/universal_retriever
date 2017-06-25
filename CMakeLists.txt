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

cmake_minimum_required( VERSION 3.8.0 )

set(UniversalRetriever_VERSION_MAJOR 0)
set(UniversalRetriever_VERSION_MINOR 1)

project(
    UniversalRetriever
    VERSION "${UniversalRetriever_VERSION_MAJOR}.${UniversalRetriever_VERSION_MINOR}"
    LANGUAGES CXX
)

# Set up basic package files

include(CMakePackageConfigHelpers)

set(UniversalRetriever_INCLUDE_DIRS include)

configure_package_config_file("cmake/UniversalRetrieverConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/UniversalRetrieverConfig.cmake"
    INSTALL_DESTINATION share/cmake
    PATH_VARS UniversalRetriever_INCLUDE_DIRS
)

write_basic_package_version_file("UniversalRetrieverVersion.cmake"
    VERSION 0.1
    COMPATIBILITY SameMajorVersion
)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/UniversalRetrieverConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/UniversalRetrieverVersion.cmake"
    DESTINATION share/cmake
)

set(UniversalRetrieverAPI "api-1.0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

if( CMAKE_HOST_WIN32 )
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Default documentation
option(BUILD_DOCUMENTATION "If ON the documentation will be built (requires Doxygen)" OFF)

# Shared library build
set(BUILD_SHARED_LIBS ON)

# Include local functions
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_options.cmake)

# Set the default for Clang-tidy
find_program(CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Absolute path to the clang-tidy executable (if found)"
)
IF( CLANG_TIDY_EXE )

    set(CMAKE_CXX_CLANG_TIDY
        "${CLANG_TIDY_EXE}"
        "-checks=boost-*,modernize-*"
        "-analyze-temporary-dtors"
        "-warnings-as-errors=*"
    )

ENDIF()

#### Output log
message("############ COMPILER ############")
message("Compiler ID : ${CMAKE_CXX_COMPILER_ID}")
message("Compiler path : ${CMAKE_CXX_COMPILER}")
message("Compiler version : ${CMAKE_CXX_COMPILER_VERSION}")
message("############ COMPILER ############")

##################
## Dependencies ##
##################

add_subdirectory( include )
add_subdirectory( src )

if( BUILD_DOCUMENTATION )
  add_subdirectory( doc )
endif()

option( BUILD_UNIT_TEST "Enable the build of unit tests" ON )

if( BUILD_UNIT_TEST )
  enable_testing()
  add_subdirectory( test )
endif()

###############
## Packaging ##
###############

SET(CPACK_GENERATOR "TGZ;DEB")
SET(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/packages")
SET(CPACK_PACKAGE_VERSION_MAJOR "${UniversalRetriever_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${UniversalRetriever_VERSION_MINOR}")
SET(CPACK_SOURCE_IGNORE_FILES "/CVS/;/.git/;.#;/#;.*~;cscope.*;/nbproject/;/build*/")
SET(CPACK_PACKAGE_CONTACT "alalazo")
INCLUDE( CPack )
