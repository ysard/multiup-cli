RELEASE_NAME := $(shell git tag | tail -n 1 | head -c -1)

build:
	mkdir -p build

compile_gnulinux: build
	cd build && cmake .. && make -j

compile_win32: build
	cd build && cmake .. -G "NMake Makefiles" && nmake

translations:
	make -f internationalization/Makefile mo

deb: build translations
	# Move compiled translations to share directory
	cp internationalization/multiup-cli.mo debian_package/multiup-cli/usr/share/locale/en_GB/LC_MESSAGES/
	cd build && make package
	cd build && lintian -EvIL +pedantic multiup-cli_${RELEASE_NAME}.deb

memory_analysis_win32:
	drmemory -logdir ./logs -- "./build/Release/multiup-cli.exe"

clean:
	rm -rf ./build

release: compile_gnulinux deb
