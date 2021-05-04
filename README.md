# Brickr

## Setup

For Debian Buster install following dependancies:
```sh
sudo apt install build-essential qt5-defaults libqt5svg5-dev libboost-graph-dev
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
