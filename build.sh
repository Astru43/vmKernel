#!/bin/bash
cd string/
make install-headers
make
make install
cd ..
make install-headers
make install
