#!/bin/bash

sudo apt-get -y install cmake --assume-yes
sudo apt-get install libomp-dev --assume-yes

sudo apt-get install git --assume-yes
git clone http://git.tiker.net/trees/boost-numeric-bindings.git

sudo apt-get install libboost-all-dev --assume-yes
wget http://downloads.sourceforge.net/project/boost/boost/1.65.1/boost_1_65_1.tar.gz
tar -zxvf boost_1_65_1.tar.gz
cd boost_1_65_1
./bootstrap.sh --with-python-version=3.6 --prefix=/usr
./b2
sudo ./b2 install
sudo ldconfig
cd /usr/lib/x86_64-linux-gnu/
cp libboost* ../
sudo unlink libboost_python.so
sudo ln -s /usr/lib/x86_64-linux-gnu/libboost_python-py36.so /usr/lib/x86_64-linux-gnu/libboost_python.so

sudo apt-get install fftw3-dev --assume-yes
sudo apt-get install libblas-dev liblapack-dev --assume-yes

sudo apt install python3-pip --assume-yes
sudo pip3 install numpy scipy
sudo apt-get install python3-pyqt5 --assume-yes
sudo apt-get install libpng-dev --assume-yes
sudo apt-get install zlib1g-dev --assume-yes
sudo pip3 install matplotlib


