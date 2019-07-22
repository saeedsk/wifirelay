#!/usr/bin/bash
# Saeed Karimabadi, July 2019
# run me as follow:
# . ./setup.sh

WORKING_DIR=$PWD

TOOLCHAIN_INSTALLER="xtensa-lx106-elf-linux64-1.22.0-92-g8facf4c-5.2.0.tar.gz"
TOOLCHAIN_DIR="xtensa-lx106-elf"
SDK="ESP8266_RTOS_SDK"

# Install Prerequisites
# sudo apt-get install gcc git wget make libncurses-dev flex bison gperf python python-serial
# sudo adduser $USER dialout
# sudo chmod 666 /dev/ttyUSB0

cd ..

if [ ! -d $TOOLCHAIN_DIR ]; then
if [ ! -f $TOOLCHAIN_INSTALLER ]; then
	echo "[setup] xtensa toolchain installer '$TOOLCHAIN_INSTALLER' doesn't exist, downloding the toolchain $FILE exists."
	wget https://dl.espressif.com/dl/xtensa-lx106-elf-linux64-1.22.0-92-g8facf4c-5.2.0.tar.gz
fi
	echo "[setup] Installing xtensa toolchain ..."
	tar -zxvf ./xtensa-lx106-elf-linux64-1.22.0-92-g8facf4c-5.2.0.tar.gz
fi

if [ ! -d $SDK ]; then
	git clone https://github.com/espressif/ESP8266_RTOS_SDK.git
fi

cd $WORKING_DIR

export IDF_PATH=$WORKING_DIR/../$SDK
echo $IDF_PATH

echo "[setup] updating $SDK git repo"
git -C $IDF_PATH pull

export SDK_PATH=$IDF_PATH
export BIN_PATH=$WORKING_DIR/../$TOOLCHAIN_DIR/bin

# Check if xtensa path is not included in the path then includ eit
[[ ":$PATH:" != *":$BIN_PATH:"* ]] && export PATH="$BIN_PATH:${PATH}"


pip2 install -q --user -r $IDF_PATH/requirements.txt
pip2 install esptool
