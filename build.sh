gcc -Wall -Wextra -Wpedantic -Werror -Isrc include/swagunit.h -o swagunit.o
ar rcs libswagunit.a swagunit.o
rm -rf swagunit.o
