#!bin/bash

warn="-Wall -Wextra -Werror -g"
gnl_file="./get_next_line.c ./get_next_line_utils.c"
gnl_test=$1

clang $warn $gnl_file $gnl_test -I. -D BUFFER_SIZE=2 -o gnl_test.o

