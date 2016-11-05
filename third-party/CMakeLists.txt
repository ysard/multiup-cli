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

MESSAGE(STATUS "Creates a custom target for libcurl")

# Add external project
# https://cmake.org/cmake/help/v3.0/module/ExternalProject.html
include(ExternalProject)

ExternalProject_Add(
     libcurl
     SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl-7.44.0
     INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl-7.44.0/build
     CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/curl-7.44.0/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/curl-7.44.0/build --disable-tftp --disable-sspi --disable-ipv6 --disable-ldaps --disable-ldap --disable-telnet --disable-pop3 --disable-ftp --without-ssl --disable-imap --disable-smtp --disable-pop3 --disable-rtsp --disable-gopher --disable-ares --without-ca-bundle --disable-warnings --disable-manual --without-nss --enable-shared --without-zlib --without-random --disable-crypto-auth --disable-proxy --disable-verbose --enable-hidden-symbols --without-libidn --without-librtmp
     BUILD_COMMAND ${MAKE}
     LOG_CONFIGURE 0
     LOG_BUILD 1
     LOG_INSTALL 1
     BUILD_IN_SOURCE 1
)

ExternalProject_Get_Property(libcurl SOURCE_DIR)
ExternalProject_Get_Property(libcurl INSTALL_DIR)

MESSAGE(STATUS "Curl source dir: " ${SOURCE_DIR})
MESSAGE(STATUS "Curl install dir: " ${INSTALL_DIR})
