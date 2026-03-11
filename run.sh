#!/bin/bash

if [ ! -f build/app ]; then
    echo "L'exécutable n'existe pas encore. Lance ./build.sh d'abord."
    exit 1
fi


./build/app