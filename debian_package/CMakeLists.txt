# This file is part of multiup-cli.
#
# multiup-cli is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# multiup-cli is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with multiup-cli.  If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2013-2016 Ysard <ysard@users.noreply.github.com>
# www.multiup.org

# https://cmake.org/cmake/help/v3.0/module/CPackDeb.html
# https://cmake.org/Wiki/CMake:CPackPackageGenerators#DEB_.28UNIX_only.29
IF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
    INCLUDE(InstallRequiredSystemLibraries)

    SET(CPACK_SET_DESTDIR "on")
    SET(CPACK_PACKAGING_INSTALL_PREFIX "/tmp")
    SET(CPACK_GENERATOR "DEB")


    # user informations
    SET(CPACK_PACKAGE_DESCRIPTION "Command line tool for www.multiup.org")
    SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Command line tool for www.multiup.org")
    SET(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/ysard/multiup-cli")
    # SET(CPACK_PACKAGE_VENDOR "")
    SET(CPACK_PACKAGE_CONTACT "Ysard <ysard@users.noreply.github.com>")

    # version
    # SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
    # SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
    # SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
    SET(CPACK_PACKAGE_VERSION "${VERSION}")
    SET(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${VERSION}")
    SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${VERSION}")

    # dependencies
    # Automatic fill
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS YES)
    SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libcurl4-gnutls (>= 7.38.0)")
    SET(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
    SET(CPACK_DEBIAN_PACKAGE_SECTION "web")
    SET(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})

    # additional files
    set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_SOURCE_DIR}/debian_package/${CMAKE_PROJECT_NAME}/DEBIAN/postrm;")

    message("Copying locales")
    # In: ${CPACK_PACKAGE_DIRECTORY}/_CPack_Packages/Linux/DEB/${CPACK_PACKAGE_FILE_NAME}/usr/
    INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/debian_package/${CMAKE_PROJECT_NAME}/usr/share
            DESTINATION ${CPACK_PACKAGE_DIRECTORY}/usr/
            FILES_MATCHING PATTERN "*.mo")

    message("Copying copyright")
    INSTALL(FILES ${CMAKE_SOURCE_DIR}/debian_package/${CMAKE_PROJECT_NAME}/DEBIAN/copyright
            DESTINATION ${CPACK_PACKAGE_DIRECTORY}/usr/share/doc/${CMAKE_PROJECT_NAME}/)

    SET(CPACK_COMPONENTS_ALL Libraries ApplicationData)
    INCLUDE(CPack)

ENDIF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
