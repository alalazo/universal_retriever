function(set_warning_flags target)
    # Sets the warning flags for a given target

    if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

        target_compile_options(
            ${target}
            PRIVATE
            "-Wall;-Werror;-pedantic"
        )

    elseif( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )

        target_compile_options(
            ${target}
            PRIVATE
            "-Wall;-Werror;-pedantic;-Wdocumentation"
        )

    elseif( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )

        target_compile_options(
            ${target}
            PRIVATE
            "/W4"
        )

    else()

        message(ERROR "Detected an unsupported compiler")

    endif()

endfunction()

function(set_rpath target)
    # Sets the INSTALL_RPATH_USE_LINK_PATH property true for a given target

    set_target_properties(${target}
        PROPERTIES
            INSTALL_RPATH_USE_LINK_PATH ON
    )

endfunction()