#!/bin/bash

for element in $(find . -type d -name "struct_*"); do
    if [ "$element" = "./struct_node" ]; then
        continue
    else
        tmp=$(echo ${element} | cut -d'/' -f 2)
        tmp=$(echo ${tmp} | cut -d'_' -f 2)
        make unit ${tmp}
        make test ${tmp}
    fi
done