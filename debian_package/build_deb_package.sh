#!/bin/bash

# Localisation du binaire
bin_dir=../build/
translations_dir=../internationalization/
# Nom du répertoire du projet DEBIAN
project_name=multiup-cli
# Nom de l'executable à packager
app_name=multiup-cli
# Version du programme
version=0.4.1

# Pour les dépendances:
# http://manpages.ubuntu.com/manpages/hardy/fr/man1/dpkg-depcheck.1.html
# => sudo apt-get install devscripts

# Voir dépendances d'un programme déjà installé:
# apt-cache show programme

# Dépendances de compilation (Build-Depends du fichier control):
# pbuilder est un outil indispensable pour tester les Build Depends
# dpkg-depcheck -b debian/rules build

# Dépendances d'exécution
# dpkg-depcheck -m ./multiupv2
# ldd ./multiupv2
#libicui18n.so.52 libicui18n.so.53
#libicuuc.so.52 => 53
#libicudata.so.52 => 53
# Connaitre le nom du paquet responsable d'une librairie:
# dpkg -S libicudata.so.52


#Depends: libcurl4-openssl-dev (>=7.19.7), libqt4-network (>=4:4.7.0), libqt4-xmlpatterns (>=4:4.7.0), libqt4-dbus (>=4:4.7.0), libqt4-xml (>=4:4.7.0), libqt4-gui (>=4:4.7.0), libqt4-core (>=4:4.7.0)
#Build-Depends: libcurl4-openssl-dev (>=7.19.7), libqt4-network (>=4:4.7.0), libqt4-xmlpatterns (>=4:4.7.0), libqt4-dbus (>=4:4.7.0), libqt4-xml (>=4:4.7.0), libqt4-gui (>=4:4.7.0), libqt4-core (>=4:4.7.0)
echo "Nettoyage..."
rm -rf /tmp/$project_name/

echo
echo "Update control..."
sed -i "/Version:/c\Version: $version" ./$project_name/DEBIAN/control

echo
echo "Copie du binaire & traductions..."
mkdir -p ./$project_name/usr/bin/
mkdir -p ./$project_name/usr/share/locale/en_GB/LC_MESSAGES/
cp $bin_dir/$app_name ./$project_name/usr/bin/$app_name
cp $translations_dir/multiup_cli.mo ./$project_name/usr/share/locale/en_GB/LC_MESSAGES/

echo
echo "Calcul des sommes de controle..."
cd ./$project_name
find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum > ./DEBIAN/md5sums
cd ..

echo
echo "Copie du dossier dans /tmp/ et attribution des droits ( >755 et <775 au lieu de 777 sur ntfs)..."
cp -R ./$project_name /tmp/$project_name
chmod 775 /tmp/$project_name/DEBIAN/*
chmod 644 /tmp/$project_name/usr/share/locale/en_GB/LC_MESSAGES/*
#chown -R root:root /tmp/$project_name/usr/share/*

echo
echo "Empaquetage..."
dpkg-deb -vD --build /tmp/$project_name /tmp/${project_name}_${version}_amd64.deb


echo
echo "Nettoyage..."
rm -rf /tmp/$project_name/
mv /tmp/${project_name}_${version}_amd64.deb .

echo
echo "Le paquet deb est là !"
echo "Désinstallation: dpkg --remove --purge"

exit


Tous les paquets donnés par ldd:
linux-vdso.so.1 (0x00007ffd981b0000)
        libcurl.so.4 => /usr/lib/x86_64-linux-gnu/libcurl.so.4 (0x00007f879e052000)
        libQt5Widgets.so.5 => /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5 (0x00007f879d7fd000)
        libQt5Gui.so.5 => /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5 (0x00007f879d0c7000)
        libQt5Network.so.5 => /usr/lib/x86_64-linux-gnu/libQt5Network.so.5 (0x00007f879cd6a000)
        libQt5Core.so.5 => /usr/lib/x86_64-linux-gnu/libQt5Core.so.5 (0x00007f879c62e000)
        libGL.so.1 => /usr/lib/x86_64-linux-gnu/libGL.so.1 (0x00007f879c2fe000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f879c0e1000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f879bdd6000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f879bad5000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f879b8bf000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f879b516000)
        libidn.so.11 => /usr/lib/x86_64-linux-gnu/libidn.so.11 (0x00007f879b2e2000)
        librtmp.so.1 => /usr/lib/x86_64-linux-gnu/librtmp.so.1 (0x00007f879b0c4000)
        libssh2.so.1 => /usr/lib/x86_64-linux-gnu/libssh2.so.1 (0x00007f879ae9b000)
        libssl.so.1.0.0 => /usr/lib/x86_64-linux-gnu/libssl.so.1.0.0 (0x00007f879ac3b000)
        libcrypto.so.1.0.0 => /usr/lib/x86_64-linux-gnu/libcrypto.so.1.0.0 (0x00007f879a840000)
        libgssapi_krb5.so.2 => /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so.2 (0x00007f879a5f6000)
        libkrb5.so.3 => /usr/lib/x86_64-linux-gnu/libkrb5.so.3 (0x00007f879a322000)
        libk5crypto.so.3 => /usr/lib/x86_64-linux-gnu/libk5crypto.so.3 (0x00007f879a0f1000)
        libcom_err.so.2 => /lib/x86_64-linux-gnu/libcom_err.so.2 (0x00007f8799eed000)
        liblber-2.4.so.2 => /usr/lib/x86_64-linux-gnu/liblber-2.4.so.2 (0x00007f8799cde000)
        libldap_r-2.4.so.2 => /usr/lib/x86_64-linux-gnu/libldap_r-2.4.so.2 (0x00007f8799a8c000)
        libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f8799871000)
        libgobject-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0 (0x00007f879961f000)
        libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f8799310000)
        libX11.so.6 => /usr/lib/x86_64-linux-gnu/libX11.so.6 (0x00007f8798fcd000)
        libpng12.so.0 => /lib/x86_64-linux-gnu/libpng12.so.0 (0x00007f8798da6000)
        libharfbuzz.so.0 => /usr/lib/x86_64-linux-gnu/libharfbuzz.so.0 (0x00007f8798b4f000)
        libicui18n.so.52 => /usr/lib/x86_64-linux-gnu/libicui18n.so.52 (0x00007f879873d000)
        libicuuc.so.52 => /usr/lib/x86_64-linux-gnu/libicuuc.so.52 (0x00007f87983bf000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f87981bb000)
        librt.so.1 => /lib/x86_64-linux-gnu/librt.so.1 (0x00007f8797fb3000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f879e2c6000)
        libnvidia-tls.so.352.30 => /usr/lib/x86_64-linux-gnu/tls/libnvidia-tls.so.352.30 (0x00007f8797db0000)
        libnvidia-glcore.so.352.30 => /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.352.30 (0x00007f879531e000)
        libXext.so.6 => /usr/lib/x86_64-linux-gnu/libXext.so.6 (0x00007f879510c000)
        libgnutls-deb0.so.28 => /usr/lib/x86_64-linux-gnu/libgnutls-deb0.so.28 (0x00007f8794ded000)
        libhogweed.so.2 => /usr/lib/x86_64-linux-gnu/libhogweed.so.2 (0x00007f8794bbe000)
        libnettle.so.4 => /usr/lib/x86_64-linux-gnu/libnettle.so.4 (0x00007f879498c000)
        libgmp.so.10 => /usr/lib/x86_64-linux-gnu/libgmp.so.10 (0x00007f8794709000)
        libgcrypt.so.20 => /lib/x86_64-linux-gnu/libgcrypt.so.20 (0x00007f8794427000)
        libkrb5support.so.0 => /usr/lib/x86_64-linux-gnu/libkrb5support.so.0 (0x00007f879421b000)
        libkeyutils.so.1 => /lib/x86_64-linux-gnu/libkeyutils.so.1 (0x00007f8794017000)
        libresolv.so.2 => /lib/x86_64-linux-gnu/libresolv.so.2 (0x00007f8793e00000)
        libsasl2.so.2 => /usr/lib/x86_64-linux-gnu/libsasl2.so.2 (0x00007f8793be4000)
        libffi.so.6 => /usr/lib/x86_64-linux-gnu/libffi.so.6 (0x00007f87939dc000)
        libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f879376e000)
        libxcb.so.1 => /usr/lib/x86_64-linux-gnu/libxcb.so.1 (0x00007f879354c000)
        libfreetype.so.6 => /usr/lib/x86_64-linux-gnu/libfreetype.so.6 (0x00007f87932a1000)
        libgraphite2.so.3 => /usr/lib/x86_64-linux-gnu/libgraphite2.so.3 (0x00007f8793085000)
        libicudata.so.52 => /usr/lib/x86_64-linux-gnu/libicudata.so.52 (0x00007f8791818000)
        libp11-kit.so.0 => /usr/lib/x86_64-linux-gnu/libp11-kit.so.0 (0x00007f87915d2000)
        libtasn1.so.6 => /usr/lib/x86_64-linux-gnu/libtasn1.so.6 (0x00007f87913be000)
        libgpg-error.so.0 => /lib/x86_64-linux-gnu/libgpg-error.so.0 (0x00007f87911ac000)
        libXau.so.6 => /usr/lib/x86_64-linux-gnu/libXau.so.6 (0x00007f8790fa8000)
        libXdmcp.so.6 => /usr/lib/x86_64-linux-gnu/libXdmcp.so.6 (0x00007f8790da3000)