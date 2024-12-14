gcc -Wall -Wextra -Wpedantic -Werror swagunit.h -o swagunit.o
ar rcs libswagunit.a swagunit.o
rm -rf swagunit.o
