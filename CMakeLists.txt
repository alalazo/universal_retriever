CMAKE_MINIMUM_REQUIRED( VERSION 3.0.0 )

PROJECT( 
  UniversalRetriever
  VERSION 0.1
  LANGUAGES CXX
)

###################
## Build options ##
###################

#### Default build type
IF( NOT CMAKE_BUILD_TYPE )
  SET (CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
      "Choose the type of build, RelWithDebInfo will be the default." FORCE)
ENDIF()

#### Shared library build
OPTION(BUILD_SHARED_LIBS "Create shared libraries instead of static ones" ON)

#### Compiler flags
IF( CMAKE_COMPILER_ID STREQUAL "GNU")
  SET(CXX_WARNING_LEVEL "-Wall -Werror -pedantic")
ELSEIF( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" ) 
  SET(CXX_WARNING_LEVEL "-Wall -Werror -pedantic -Wdocumentation")
ENDIF()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_WARNING_LEVEL} -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g")

#### Output log
STRING( TOUPPER "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}" SPECIFIC_BUILD)
MESSAGE("############ COMPILER OPTIONS ############")
MESSAGE("Compiler ID : ${CMAKE_CXX_COMPILER_ID}")
MESSAGE("Compiler path : ${CMAKE_CXX_COMPILER}")
MESSAGE("Compiler version : ${CMAKE_CXX_COMPILER_VERSION}")
MESSAGE("CXX flags (base) : ${CMAKE_CXX_FLAGS}")
MESSAGE("CXX flags (build-type) : ${${SPECIFIC_BUILD}}")
MESSAGE("############ COMPILER OPTIONS ############")

##################
## Dependencies ##
##################

FIND_PACKAGE( Boost 1.56 REQUIRED )
