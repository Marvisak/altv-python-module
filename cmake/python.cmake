include(ProcessorCount)

function(DownloadPython py_version)
    set(_download_link https://www.python.org/ftp/python/${py_version}/Python-${py_version}.tgz)
    get_filename_component(_filename ${_download_link} NAME)
    set(_path ${CMAKE_CURRENT_BINARY_DIR}/${_filename})
    if (NOT EXISTS ${_path})
        message("Downloading ${_download_link}")
        file(DOWNLOAD ${_download_link} ${_path})
        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xfz ${_path}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                RESULT_VARIABLE rv)
        if (NOT rv EQUAL 0)
            message(FATAL_ERROR "extraction failed")
        endif()
    endif()
endfunction()

function(CompilePython py_version)
    set(_filename Python-${py_version})
    set(_path ${CMAKE_CURRENT_BINARY_DIR}/${_filename})
    if (UNIX)
        if (NOT EXISTS ${_path}/pyconfig.h)
            message("Configuring Python")
            execute_process(COMMAND ./configure --enable-optimizations --enable-shared
                    WORKING_DIRECTORY ${_path} OUTPUT_QUIET)

            ProcessorCount(cores)
            message("Compiling Python")
            execute_process(COMMAND make -j${cores}
                    WORKING_DIRECTORY ${_path} OUTPUT_QUIET)
        endif()

    else()
        if (NOT EXISTS ${_path}/PCbuild/amd64)
            message("Compiling Python")
            execute_process(COMMAND PCBuild\\build.bat -p x64
                    WORKING_DIRECTORY ${_path} OUTPUT_QUIET)
        endif()
    endif()
endfunction()