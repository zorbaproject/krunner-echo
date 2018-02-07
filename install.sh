#!/bin/bash
# sudo apt-get install extra-cmake-module libkf5i18n-dev libkf5service-dev libkf5textwidgets-dev libkf5runner-dev libkf5configwidgets-dev plasma-framework-dev
#rm -r build
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=`kf5-config --prefix` -DQT_PLUGIN_INSTALL_DIR=`kf5-config --qt-plugins`
make
sudo make install
#kquitapp krunner
#krunner
