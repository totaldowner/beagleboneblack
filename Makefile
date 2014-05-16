# Make test binaries

LIBDIR?=./io
INCDIR?=./io
BINDIR?=./bin
CFLAGS+= -Wall -I${INCDIR} -O2 -mtune=cortex-a8 -march=armv7-a

all:
	gcc ${CFLAGS} tests/gpiotest.c io/gpio.c -o ${BINDIR}/gpiotest 

clean:
	rm -rf ${BINDIR}/*
