#!/bin/bash
#
# set_path: Adds the current working directory to PATH 

# test if PWD is already in PATH

if [[ ":$PATH:" != *":$PWD:"* ]]; then
  PATH="${PATH}":"$PWD"
fi

