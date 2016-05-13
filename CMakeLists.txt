#This file is part of multiup_cli.
#
#    multiup_cli is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    multiup_cli is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with multiup_cli.  If not, see <http://www.gnu.org/licenses/>.
#
#    Copyright 2013-2016 Lex
#    www.multiup.org

cmake_minimum_required(VERSION 3.0) # Pour éviter un warning au lancement de CMake, on doit préciser la version minimale

# Nom du projet
project(multiup-cli)

# Librairies
if(WIN32)
	if(CMAKE_COMPILER_IS_GNUCXX)
		# For g++/gcc compiler (mingw32)
		# curl
		set(curl_lib_name libcurl.a)
		set(curl_lib_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.28.1-devel-mingw32/lib/)
		set(curl_include_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.28.1-devel-mingw32/include/)
	
	else()
		# For Visual Studio etc compiler
		# curl
		#set(curl_lib_name libcurl.lib)
		#set(curl_lib_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.29-nmake/lib/)
		#set(curl_include_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.29-nmake/include/)
		
		set(curl_lib_name libcurl_a.lib)
		set(curl_lib_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-devel-nmake/lib/)
		set(curl_include_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-devel-nmake/include/)
	endif()
	
	# Preprocessor directive: #define LINUX
	add_definitions(-DWINDOWS)
endif()

if(UNIX)
	if(${CMAKE_SYSTEM_PROCESSOR} MATCHES armv6l)
		# Raspberry pi
		# curl
		set(curl_lib_name curl)
		set(curl_lib_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-armv6l/lib/)
		set(curl_include_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-armv6l/include/)

	else()
		# Autres systèmes unix
		# curl
		set(curl_lib_name curl)
		set(curl_lib_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-devel-unix-static/lib/)
		set(curl_include_dir ${CMAKE_SOURCE_DIR}/dependances-developpement/curl-7.44.0-devel-unix-static/include/)
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
	# For g++/gcc compiler (mingw32)
	
	MESSAGE(STATUS "Activation c++11")
	#autre syntaxe: add_definitions(-std=gnu++0x)
	
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
else()
	# For Visual Studio etc compiler
	# MSVC does not require any special flags for c++11
	
	# Optimisation de l'éditeur de lien pour les librairies statiques
	#sinon => json_vc71_libmt.lib(json_value.obj) : .netmodule ou module MSIL compilé avec /GL
	#trouvée; redémarrage de l'édition de liens avec /LTCG;
	#ajoutez /LTCG à la ligne de commande de l'édition de liens pour améliorer les performances de l'éditeur de liens
	set(CMAKE_EXE_LINKER_FLAGS "/LTCG" )
	ADD_DEFINITIONS(-D_HAS_ITERATOR_DEBUGGING=0)
endif()

include_directories(${curl_include_dir})
#link_directories(${jsoncpp_lib_dir}) #=> foireux ! déconseillé dans la doc et en tuto sur le sdz !
find_library(CURL_LIB ${curl_lib_name} ${curl_lib_dir} NO_DEFAULT_PATH)
#NO_DEFAULT_PATH évite que la recherche s'arrete dès que la lib du système a été trouvée (surtout sur linux)


MESSAGE(STATUS "Cmake prefix: ${CMAKE_SOURCE_DIR}")
MESSAGE(STATUS "Curl libraries at: ${curl_lib_dir}")
MESSAGE(STATUS "Curl libraries found at: ${CURL_LIB}")

# Preprocessor definitions for this target. 
# IMPORTANT ! sinon ça link en shared et pas en static
add_definitions(-DCURL_STATICLIB)

# Ajouter toutes les sources dans le dossier (variable source_files)
#file(
#    GLOB_RECURSE
#    source_files
#    ./*
#)
#file (GLOB GENERAL_SRC 
#    json/*.h
#)

# Déclaration de l'exécutable
add_executable(
      multiup-cli #Target names may not contain slashes. This is not a supported use case.
      ../main.cpp
      ../mainClass.h
      ../mainClass.cpp
	  ../colors_in_the_shell.h
	  ../colors_in_the_shell.cpp
      ../Config.h
	  
	  ../dependances-developpement/jsoncpp/dist/json/json.h
	  ../dependances-developpement/jsoncpp/dist/json/json-forwards.h
	  ../dependances-developpement/jsoncpp/dist/jsoncpp.cpp
)

target_link_libraries(
      multiup-cli
      ${CURL_LIB}
)

# Forcer la compilation en release
set(CMAKE_BUILD_TYPE "Release")

# Installation
if(UNIX)
	INSTALL(TARGETS multiup-cli DESTINATION ${INSTALL_DIR}/bin)
endif()

if(WIN32)
	#INSTALL(TARGETS multiup-cli DESTINATION c:/windows/)
endif()


#notes :
#make VERBOSE=1

## Compiler flags
#if(CMAKE_COMPILER_IS_GNUCXX)
#    set(CMAKE_CXX_FLAGS "-O2")        ## Optimize
#    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
#endif()

#CMAKE_EXE_LINKER_FLAGS
#CMAKE_SHARED_LINKER_FLAGS
#CMAKE_MODULE_LINKER_FLAGS
#STATIC_LIBRARY_FLAGS Extra flags to use when linking static libraries