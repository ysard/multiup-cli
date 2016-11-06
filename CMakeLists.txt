# This file is part of multiup_cli.
#
# multiup_cli is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# multiup_cli is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with multiup_cli.  If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2013-2016 Lex
# www.multiup.org

# We require CMake >= 3.0
# Minimal version is needed in order to avoid warnings
cmake_minimum_required(VERSION 3.0)

# Set projectname (must be done AFTER setting configurationtypes)
set(VERSION "0.4.1")
project(multiup-cli)

# add dependencies


# Libraries & platform specific settings
if(WIN32)
    if(CMAKE_COMPILER_IS_GNUCXX)
        # For g++/gcc compiler (mingw32)
        set(curl_lib_name libcurl.a)
        set(curl_lib_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.28.1-devel-mingw32/lib/)
        set(curl_include_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.28.1-devel-mingw32/include/)
    else()
        # For Visual Studio etc compiler
        set(curl_lib_name libcurl_a.lib)
        set(curl_lib_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0-devel-nmake/lib/)
        set(curl_include_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0-devel-nmake/include/)
        #set(curl_lib_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0/build/lib/)
        #set(curl_include_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0/build/include/)
    endif()

    # Preprocessor directive: #define WINDOWS
    add_definitions(-DWINDOWS)
endif()

if(UNIX)
    if(${CMAKE_SYSTEM_PROCESSOR} MATCHES armv6l)
        # Raspberry pi
        set(curl_lib_name curl)
        set(curl_lib_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0-armv6l/lib/)
        set(curl_include_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0-armv6l/include/)
    else()
        # Other *NIX systems
        set(curl_lib_name curl)
        set(curl_lib_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0/build/lib/)
        set(curl_include_dir ${CMAKE_SOURCE_DIR}/third-party/curl-7.44.0/build/include/)
    endif()

    # Preprocessor directive: #define LINUX
    add_definitions(-DLINUX)
    # Enable internationalization with gettext
    add_definitions(-DENABLE_NLS)
    # Locales directory
    add_definitions(-DLOCALES="/usr/share/locale")
endif()

# Compilers FLAGS (c++ 11 & linker options)
if(CMAKE_COMPILER_IS_GNUCXX)
    # For g++/gcc/mingw32 compiler

    # Optimize
    set(CMAKE_CXX_FLAGS "-O2")
    # Strip binary
    set(CMAKE_EXE_LINKER_FLAGS "-s")

    set(warnings "-Wall -Wextra -Werror")

    # c++11
    MESSAGE(STATUS "Activation of c++11")
    # Other syntax: add_definitions(-std=gnu++0x)
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
        message(WARNING "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # For Visual Studio etc compiler
    # MSVC does not require any special flags for c++11

    set(warnings "/W4 /WX /EHsc")

    # Optimization of linker for static libs
    # Avoid this error: json_vc71_libmt.lib(json_value.obj) : .netmodule ou module MSIL compilé avec /GL
    # Add /LTCG to the command line of the linker
    set(CMAKE_EXE_LINKER_FLAGS "/LTCG" )
    ADD_DEFINITIONS(-D_HAS_ITERATOR_DEBUGGING=0)
endif()

include_directories(${curl_include_dir})

MESSAGE(STATUS "Cmake prefix: ${CMAKE_SOURCE_DIR}")

# Preprocessor definitions for this target.
# IMPORTANT ! STATIC linking instead of SHARED
add_definitions(-DCURL_STATICLIB)
add_definitions(-DVERSION=${VERSION})

# Executable definition
add_executable(
      multiup-cli #Target names may not contain slashes. This is not a supported use case.
      ../main.cpp
      ../mainClass.h
      ../mainClass.cpp
      ../colors_in_the_shell.h
      ../colors_in_the_shell.cpp
      ../Config.h

      ../third-party/jsoncpp/dist/json/json.h
      ../third-party/jsoncpp/dist/json/json-forwards.h
      ../third-party/jsoncpp/dist/jsoncpp.cpp
)

#link_directories(foo) #=> deprecated syntax

# Force static lib: find_library(CURL_LIB NAMES libcurl.a ...
# NO_DEFAULT_PATH avoids stop search when the system lib version is found
find_library(CURL_LIB ${curl_lib_name})
if(CURL_LIB)
    MESSAGE(STATUS "Curl library found at: ${CURL_LIB}")
else()
    # Try to use the pre-compiled library
    find_library(CURL_LIB ${curl_lib_name} ${curl_lib_dir} NO_DEFAULT_PATH)
    if(CURL_LIB)
        MESSAGE(STATUS "Curl library found at: ${CURL_LIB}")
    else()
        MESSAGE(STATUS "Curl library not found at: ${CURL_LIB} => will be built")
        add_subdirectory(third-party)
        add_dependencies(multiup-cli libcurl)
    endif()
endif()

if(CURL_LIB)
    target_link_libraries(
          multiup-cli
          # We want to use the system lib
          ${CURL_LIB}
    )
else()
    target_link_libraries(
        multiup-cli
        ${curl_lib_dir}/libcurl.a
    )
endif()

# Build in Release-mode by default if not explicitly set
if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

# Installation
if(UNIX)
    INSTALL(TARGETS multiup-cli
            DESTINATION /usr/bin)
endif()

#if(WIN32)
#    INSTALL(TARGETS multiup-cli DESTINATION c:/windows/)
#endif()


#notes :
#make VERBOSE=1

#CMAKE_EXE_LINKER_FLAGS
#CMAKE_SHARED_LINKER_FLAGS
#CMAKE_MODULE_LINKER_FLAGS
#STATIC_LIBRARY_FLAGS Extra flags to use when linking static libraries