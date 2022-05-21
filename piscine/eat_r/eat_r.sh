#!/bin/sh

eat=0

for arg in "$@";do
    eat=$(($eat+1))

        if [ "$eat" -eq "$#" ]; then
        echo -n "$arg" | tr -d 'r''R'
    else
    echo -n "$arg," | tr -d 'r''R'
    fi
done
echo ""
exit 0
