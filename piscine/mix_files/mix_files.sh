#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: mix_files file1 file2" >> /dev/stderr
    exit 1
fi
a=0
b=0
if [ ! -f "$1" ] && [ ! -f "$2" ]; then
    exit 1
elif [ ! -f "$1" ]; then
    cat "$2"
elif [ ! -f "$2" ]; then
    cat "$1"
else

    for i in $(cat "$1" -A); do
        a=$((a+1))
    done
    for j in $(cat "$2" -A); do
        b=$((b+1))
    done

    if [ $a -gt $b ]; then
        c=0
        while [ $c -ne $((b+1)) ]; do
            head "$1" -n $c | tail -n 1
            head "$2" -n $c | tail -n 1
            c=$((c+1))
        done
        while [ $c -ne $((a+1)) ]; do
            head "$1" -n $c | tail -n 1
            c=$((c+1))
        done
    else
        c=0
        while [ $c -ne $((a + 1)) ]; do
            head "$1" -n $c | tail -n 1
            head "$2" -n $c | tail -n 1
            c=$((c+1))
        done
        while [ $c -ne $((b+1)) ]; do
            head "$2" -n $c | tail -n 1
            c=$((c+1))
        done
    fi
fi
