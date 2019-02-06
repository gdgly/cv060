Introduction
------------
  The program 'simple-mbgateway' shows you an implementation of a simple modbus gateway. This program has hard coded settings which
drive TCP masters to link with a RTU serial (RS232) slave at port 2 and bind a RTU serial(RS232) master at port 1 to link with a
TCP slave on 192.168.127.100:502. To change settings, please look into the source in 'simple-mbgateway.c'. Remember to recompile the
program upon any change being made.

Design
------
  This gateway run in two main threads, 'serial_master' and 'serial_slave'. The former detects data arrival from the serial port and
the spawns another thread 'serial_master_child' to handle the process of modbus data conversion between serial and network connections.
This spawn thread applies a 3-second timeout block-read to the serial port.

(serial_master)
+-----------+      +-----------------------------+      +--------------------------+
| open port | ---> | try to connect to TCP slave | ---> | has data in serial port? |
+-----------+      +-----------------------------+      +--------------------------+
		(serial_master_child)
		+-----------+      +------------------------+      +----------------------+
		| read data | ---> | send and wait response | ---> | write to serial port |
		+-----------+      +------------------------+      +----------------------+

  Thread 'serial_slave' is similar to thread 'serial_master'. It accepts and reads data from the TCP master at startup, and upon
detecting the first piece of data, spawns a thread 'serial_slave_child' to handle the process of modbus data conversion between
serial and network connections.

(serial_slave)
+--------+      +--------------------+
| accept | ---> | read data from TCP |
+--------+      +--------------------+
		(serial_slave_child)
		+------------------------+      +-------------------+
		| send and wait response | ---> | write data to TCP |
		+------------------------+      +-------------------+

Build
-----
  1. Make sure you have modbus example library installed in your developing workstation.

  2. Type 'make' to build the program.

  3. Copy the program 'simple-mbgateway' to the target device and run the program. Before you run it, make sure you have
     example modbus library installed in your target box.
