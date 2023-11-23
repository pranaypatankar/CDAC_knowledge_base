#!/bin/bash

set -x 

FILE_1=a.bin
FILE_2=b.bin
BUFFER_SIZE=102400

rm -rf ${FILE_1} ${FILE_2}
dd if=/dev/urandom of=${FILE_1} bs=500M count=1 status=progress
sleep 1

time ./syscalls-copy.out ${FILE_1} ${FILE_2} ${BUFFER_SIZE}
diff ${FILE_1} ${FILE_2}
rm -rf ${FILE_2}
sleep 1

time ./clib-copy.out ${FILE_1} ${FILE_2} ${BUFFER_SIZE}
diff ${FILE_1} ${FILE_2}

sleep 1
rm -rf ${FILE_1} ${FILE_2}
