#!bin/bash

warn= -Wall -Wextra -Werror -g
gnl_file= $1
gnl_test= $2

clang $warn $1 $2 -I. -D BUFFER_SIZE=2 -o gnl_test.o

