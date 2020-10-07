#!/bin/bash

rt=0
for element in $(find . -type d -name "struct_*"); do
    if [ "$element" = "./struct_node" ]; then
        continue
    else
        tmp=$(echo ${element} | cut -d'/' -f 2)
        tmp=$(echo ${tmp} | cut -d'_' -f 2)
        make unit ${tmp} >> /dev/null
        echo ${tmp}
        make test ${tmp} >> /dev/null
        rt=$((rt + $?))
    fi
done
exit ${rt}