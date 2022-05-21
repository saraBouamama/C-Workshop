#!/bin/sh
cut -d':' /etc/passwd -f 3 | sort -nru
