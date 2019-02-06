Introduction
------------
  This release only for demostrates the modbus protocol and provides examples how to control serial/socket and how to
build a modbus gateway.

  The following diagram shows the architecure of modbus example library. The upper layer provides a set of APIs for
UC programmers to construct modbus applications/gateways in a higher level. These APIs hides the complexity of serial
as well as networking connections (i.e., lower layers) from programmers and eventually the implementation cost is reduced.

     +----------+  +-------+
     | mbserial |  | mbtcp |          -->  modbus master/slave functions
     +----------+  +-------+
  +-------------+  +--------------+
  | modbus_defs |  | modbus_utils |   -->  variable defines
  +-------------+  +--------------+        and low level modbus functions
       +--------+  +--------+
       | serial |  | socket |         -->  basic serial/socket functions
       +--------+  +--------+

  The middler layer defines various variables that are used in handling modbus protocols in terms of command definition
and packet formats. Finally, the lower layer wraps serial and socket operations into a set of simple functions that are
called by the upper layers.

Files and Directories
---------------------
  The library is delivered to you in source code levels. This provides a simple yet clean reference for you to understand
the inside of serial and networking functions in UC products. In addition, based on the source codes provided, you would
have a maximum flexibilty to modify them in order to fit your special needs.

  The following list itemizes the required objects for the library. Two modbus examples based on the library are also created
and organized into the list. Please check all of them before you build the programs.

- /					Example modbus library root directory
    - README				This file
- document/				Library documents,
					descripts the example library functions
- library/				Example Library source code
    - Makefile				Makefile of modbus example library
    - install.sh			Installation script used by 'Makefile'
    - serial.h				Header file of serial API library
    - serial.c				Define file of serial API library
    - socket.h				Header file of socket TCP API library
    - socket.c				Define file of socket TCP API library
    - mobdus_defs.h			Define file of modbus variables
    - modbus_utils.h			Header file of modbus utilities API
    - modbus_utils.c			Define file of modbus utilities API
    - mbserial.h			Header file of modbus serial API library
    - mbserial.c			Define file of modbus serial API library
    - mbtcp.h				Header file of modbus TCP API library
    - mbtcp.c				Define file of modbus TCP API library
- simple-mbgateway/			Simple modbus gateway,
					settings are wrote on the top of
					the file 'simple-mbgateway.c'
					More detail, read 'simple-mbgateway/README'
    - README				Detail description of 'simple-mbgateway'
    - Makefile				Makefile of 'simple-mbgateway'
    - simple-mbgateway.c		Source code of the 'simple-mbgateway'

Build and Testing
-----------------
  Follow the steps below to build modbus example library and example programs.

1. Change the directory to 'library/' and type 'make' to compile the library.

2. Type 'make install' to install the library and setup your develop environment where example programs rely on.

3. Copy (for example, via ftp) 'libmodbus.so' to the target device (i.e., UC-7420 box) and put the file into the
  directory '/usr/lib/'. With this file, you have a runtime environment.

4. Change the directory to 'simple-mbgateway/' and type 'make' to compile the 'simple-mbgateway'.

5. Copy the program 'simple-mbgateway/simple-mbgateway' to the target device and run the program. It acts as a modbus gateway.
  To verify it, connect modbus devices to the UC-7420 box. For more detailed information, please read 'simple-mbgateway/README'.
