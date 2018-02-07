# Krunner Echo plugin

This is just a simple plugin for krunner. It's basically useless, but it's the base from which you can start building your own plugins.

## Requirements ##

Main requirements should be installed with this command on Ubuntu:
```
sudo apt-get install extra-cmake-module libkf5i18n-dev libkf5service-dev libkf5textwidgets-dev libkf5runner-dev libkf5configwidgets-dev plasma-framework-dev
```
Anyway, Cmake could ask you to install other libraries.

## Installation ##
In order to compile and install this plugin you should run these commands:
```
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=`kf5-config --prefix` -DQT_PLUGIN_INSTALL_DIR=`kf5-config --qt-plugins`
make 
sudo make install
kquitapp krunner
krunner
```
If you want something easier, there are install and uninstall scripts.
