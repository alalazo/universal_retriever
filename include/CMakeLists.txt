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

set(UNIVERSAL_RETRIEVER_INSTALLED_HEADERS
    ${PROJECT_SOURCE_DIR}/include/any.h
    ${PROJECT_SOURCE_DIR}/include/Frontend.h
    ${PROJECT_SOURCE_DIR}/include/BackendInterface.h
    ${PROJECT_SOURCE_DIR}/include/HandlerInfo.h
    ${PROJECT_SOURCE_DIR}/include/UniversalRetrieverExceptions.h
)

set(UNIVERSAL_RETRIEVER_PRIVATE_HEADERS
    ${PROJECT_SOURCE_DIR}/include/HandlerMap.h
)

install(
    FILES
        ${UNIVERSAL_RETRIEVER_INSTALLED_HEADERS}
    DESTINATION
        include
)

set(UNIVERSAL_RETRIEVER_HEADERS
    ${UNIVERSAL_RETRIEVER_INSTALLED_HEADERS}
    ${UNIVERSAL_RETRIEVER_PRIVATE_HEADERS}
    PARENT_SCOPE
)