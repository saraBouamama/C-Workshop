#!/bin/sh

if [ $1 -lt 0 ]; then
    exit 1

elif [ "$2" = "square" ]; then
    echo " _________________"
    for k in $(seq $1); do
        echo "|  ___       ___  |"
        echo "| |_|_|     |_|_| |"
        echo "| |_|_|     |_|_| |"
        echo "|                 |";
    done
    echo "|        _        |"
    echo "|       | |       |"
    echo "|       | |       |"
    echo "|_______| |_______|"
    exit 0

elif [ "$2" = "triangle" ]; then
    echo " _________________"
    for k in $(seq $1); do
        echo "|                 |"
        echo "|   /\       /\   |"
        echo "|  /__\     /__\  |"
        echo "|                 |";
    done
    echo "|        _        |"
    echo "|       | |       |"
    echo "|       | |       |"
    echo "|_______| |_______|"
    exit 0

else
    exit 1

fi
