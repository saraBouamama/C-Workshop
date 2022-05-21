#!/bin/sh

if [ $# -ne 3 ]; then
    >&2 echo "Usage: ./seq.sh FIRST INCREMENT LAST"
    exit 1
fi

first="$1"
inc="$2"
last="$3"

if [ "$last" -gt "$first" ] && [ "$inc" -le 0 ]; then
    exit 1
elif [ "$last" -lt "$first" ] && [ "$inc" -ge 0 ]; then
    exit 1
fi

if [ "$first" -eq "$last" ]; then
    echo "$first"
    exit 0
fi

if [ "$last" -gt "$first" ]; then
    tmp="$first"
    while [ "$tmp" -le "$last" ]; do
        echo "$tmp"
        tmp=$((tmp + inc))
    done
    exit 0
fi

if [ "$first" -gt "$last" ]; then
    tmp="$first"
    while [ "$tmp" -ge "$last" ]; do
        echo "$tmp"
        tmp=$((tmp + inc))
    done
    exit 0
fi

echo test
exit 0
