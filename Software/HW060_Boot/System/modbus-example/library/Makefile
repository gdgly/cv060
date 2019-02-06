CC=mxscaleb-gcc
CFLAGS=
CXXFLAGS=
OBJS=serial.o socket.o mbserial.o mbtcp.o modbus_utils.o

all:	libmodbus.so

libmodbus.so: $(OBJS)
	$(CC) -shared -Wl,-soname,libmodbus.so -o libmodbus.so $(OBJS) -lc

clean:
	rm *.o libmodbus.so > /dev/null 2>&1

install: all
	./install.sh
