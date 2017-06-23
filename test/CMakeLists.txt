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

find_package( Boost 1.55 REQUIRED COMPONENTS unit_test_framework )

add_executable(test_universal_retriever
    test_main.cpp
    simple_backend_test.cpp
    SimpleBackend.h
    SimpleBackend.cpp
)

set_warning_flags(test_universal_retriever)
set_rpath(test_universal_retriever)

target_compile_definitions(test_universal_retriever
    PUBLIC
        -DBOOST_ALL_DYN_LINK
)

target_include_directories(test_universal_retriever
    PUBLIC
        ${PROJECT_SOURCE_DIR}/test
)

target_include_directories(test_universal_retriever
    PUBLIC SYSTEM
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(test_universal_retriever
    PRIVATE
        universal_retriever
        ${Boost_LIBRARIES}
)

set_target_properties(test_universal_retriever
    PROPERTIES
        FOLDER test
)


add_test(
    NAME
        run_unit_test
    COMMAND
        test_universal_retriever --report_level=detailed --build_info --log_format=XML --log_level=all --output_format=HRF --random --log_sink=test.log
)