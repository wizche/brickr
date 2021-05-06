# Brickr

## Setup

For Debian Buster install following dependancies:
```sh
sudo apt install libglu1 build-essential qt5-default libqt5svg5-dev libboost-graph-dev
```

Eventually:
```sh
sudo apt install qtcreator
```

Brickr use vcglib for model manipulation and is added as submodule dependency, be sure to pull it.

Then build with:
```sh
mkdir build/
cd build
# generate Makefile
cmake 
# make!
make
# run
./brickr
```
