::This file is part of multiup_cli.
::
::    multiup_cli is free software: you can redistribute it and/or modify
::    it under the terms of the GNU General Public License as published by
::    the Free Software Foundation, either version 3 of the License, or
::    (at your option) any later version.
::
::    multiup_cli is distributed in the hope that it will be useful,
::    but WITHOUT ANY WARRANTY; without even the implied warranty of
::    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
::    GNU General Public License for more details.
::
::    You should have received a copy of the GNU General Public License
::    along with multiup_cli.  If not, see <http://www.gnu.org/licenses/>.
::
::    Copyright 2013 Lex
::    www.multiup.org

:: Création du répertoire build pr cmake)
mkdir build
cd ./build

:: Liste des générateurs dispos sur la config => <cmake --help>
::http://www.siteduzero.com/informatique/tutoriels/introduction-aux-systemes-de-construction-logicielle-avec-cmake/cmakelists-txt-et-la-compilation-d-un-programme-simple

::set PATH=%PATH%;G:\QtSDK\mingw\bin;G:\QtSDK\Desktop\Qt\4.8.0\mingw\bin
::cmake .. -G "MinGW Makefiles"
::mingw32-make

::cmake .. -G "Visual Studio 10"
::ouvrir le projet via Visual Studio

cmake .. -G "NMake Makefiles"
nmake


:: analyse mémoire
::drmemory -logdir ./logs -- "./Release/multiup-cli.exe"

:: exécution
"./Release/multiup-cli.exe"
