CC=mxscaleb-gcc
CFLAGS=$(INCLUDE)
CXXFLAGS=

all:	simple-mbgateway

simple-mbgateway: simple-mbgateway.o
	$(CC) simple-mbgateway.o -o simple-mbgateway -lpthread -lmodbus

clean:
	rm *.o simple-mbgateway > /dev/null 2>&1

