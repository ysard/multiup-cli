# Project name
PROJECT_NAME="multiup_cli"
# Internationalization folder
NLS_FOLDER="./internationalization"

### Internationalization
make_pot:
	# Update pot model file
	xgettext -d $(PROJECT_NAME) -o $(NLS_FOLDER)/$(PROJECT_NAME).pot --keyword=_ *.cpp

make_en_po:
	# pot inherit for en_GB language
	# THIS PO FILE must be edited by the traductor !
	msginit -l en_GB -o $(NLS_FOLDER)/english.po -i $(NLS_FOLDER)/$(PROJECT_NAME).pot
	
make_mo:
	# Make final mo translation file
	msgfmt -c -v -o $(NLS_FOLDER)/$(PROJECT_NAME).mo $(NLS_FOLDER)/english.po

install_mo: make_mo
	# Install translation
	sudo cp $(NLS_FOLDER)/$(PROJECT_NAME).mo /usr/share/locale/en_GB/LC_MESSAGES/
