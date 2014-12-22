function(JOIN VALUES GLUE OUTPUT)
  string (REPLACE ";" "${GLUE}" _TMP_STR "${VALUES}")
  set (${OUTPUT} "${_TMP_STR}" PARENT_SCOPE)
endfunction()

FIND_PACKAGE(Doxygen 1.8.7 REQUIRED)

SET( doxyfile_in          ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in     )
SET( doxyfile             ${PROJECT_BINARY_DIR}/Doxyfile              )
SET( doxy_html_index_file ${CMAKE_CURRENT_BINARY_DIR}/html/index.html )
SET( doxy_output_root     ${CMAKE_CURRENT_BINARY_DIR}                 ) # Pasted into Doxyfile.in
SET( doxy_input           ${PROJECT_SOURCE_DIR}/src
                          ${PROJECT_SOURCE_DIR}/include               ) # Pasted into Doxyfile.in
#SET( doxy_examples        ${PROJECT_SOURCE_DIR}/examples              ) # Pasted into Doxyfile.in
#SET( doxy_extra_files     ${CMAKE_CURRENT_SOURCE_DIR}/mainpage.dox    ) # Pasted into Doxyfile.in
SET( doxy_exclude "${PROJECT_SOURCE_DIR}/include/HandlerMap.h" )
## If any header or source is modified, then rebuild the documentation
FOREACH( dir ${doxy_input} ${doxy_examples} )
  FILE( GLOB_RECURSE tmp_headers ${dir}/*.h   )
  FILE( GLOB_RECURSE tmp_sources ${dir}/*.cpp )
  SET ( file_dependencies ${file_dependencies} ${tmp_headers} ${tmp_sources} )
ENDFOREACH()
# Fix value lists before substitution...
JOIN("${doxy_input}" " " doxy_input)
JOIN("${doxy_exclude}" " " doxy_exclude)
CONFIGURE_FILE( ${doxyfile_in} ${doxyfile} @ONLY )    

ADD_CUSTOM_COMMAND( OUTPUT ${doxy_html_index_file}
                    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
                    # The following should be ${doxyfile} only but it will break the dependency.
                    # The optimal solution would be creating a custom_command for ${doxyfile}
                    # generation but I still have to figure out how...
                    MAIN_DEPENDENCY ${doxyfile} ${doxyfile_in}
                    DEPENDS 
                    ${doxy_extra_files} ${UniversalRetriever_INSTALLED_HEADERS} 
                    COMMENT "Generating HTML documentation")

ADD_CUSTOM_TARGET( doc ALL DEPENDS ${doxy_html_index_file} )

INSTALL( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc )  

INSTALL( 
  FILES ${PROJECT_SOURCE_DIR}/COPYING ${PROJECT_SOURCE_DIR}/COPYING.LESSER
  DESTINATION share/license
)