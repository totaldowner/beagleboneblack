# Make test binaries

LIBDIR?=./io
INCDIR?=./io
BINDIR?=./bin
OBJDIR=./obj
CFLAGS+= -Wall -I${INCDIR} -O2 -mtune=cortex-a8 -march=armv7-a
CC=gcc

all: fsgpiotest ssd1306test

ssd1306test: ${OBJDIR}/fsgpio.o ${OBJDIR}/spi.o ${OBJDIR}/ssd1306.o ${OBJDIR}/pbm.o ${OBJDIR}/ssd1306test.o
	${CC} ${CFLAGS} ${OBJDIR}/fsgpio.o ${OBJDIR}/spi.o ${OBJDIR}/pbm.o ${OBJDIR}/ssd1306.o ${OBJDIR}/ssd1306test.o -o ${BINDIR}/ssd1306test
	
fsgpiotest: ${OBJDIR}/fsgpio.o ${OBJDIR}/fsgpiotest.o
	${CC} ${CFLAGS} ${OBJDIR}/fsgpio.o ${OBJDIR}/fsgpiotest.o -o ${BINDIR}/fsgpiotest

${OBJDIR}/fsgpiotest.o: tests/fsgpiotest.c
	${CC} ${CFLAGS} -c tests/fsgpiotest.c -o ${OBJDIR}/fsgpiotest.o

${OBJDIR}/ssd1306test.o: tests/ssd1306test.c
	${CC} ${CFLAGS} -c tests/ssd1306test.c -o ${OBJDIR}/ssd1306test.o


${OBJDIR}/ssd1306.o: io/ssd1306.c
	${CC} ${CFLAGS} -c io/ssd1306.c -o ${OBJDIR}/ssd1306.o

${OBJDIR}/pbm.o: io/pbm.c
	${CC} ${CFLAGS} -c io/pbm.c -o ${OBJDIR}/pbm.o

${OBJDIR}/spi.o: io/spi.c
	${CC} ${CFLAGS} -c io/spi.c -o ${OBJDIR}/spi.o

${OBJDIR}/fsgpio.o: io/fsgpio.c
	${CC} ${CFLAGS} -c io/fsgpio.c -o ${OBJDIR}/fsgpio.o

clean:
	rm -rf ${BINDIR}/*
	rm -rf ${OBJDIR}/*
