#/bin/sh
module="modbus"
dest="/usr/local/mxscaleb/armv5b-linux"
header="mbserial.h  mbtcp.h  modbus_defs.h  modbus_utils.h  serial.h  socket.h"

for i in $header ; do
	cmd="cp $i ${dest}/include/"
	echo $cmd
	`$cmd`
done

cmd="cp libmodbus.so ${dest}/lib/"
echo $cmd
`$cmd`
