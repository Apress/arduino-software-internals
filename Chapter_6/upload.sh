#!/bin/bash
#
# a script to program a Duemilanove with a compiled sketch created by the Arduino CLI
# utility. Currently, version 0.6.0 does not have the ability to upload by any means
# except a bootloader.
#
# The following command is slightly adapted from that used in the Arduino IDE to 
# program a Duemilanove with the USBTiny programmer. It requires a filename on the
# command line, which is the name of the compiled hex file to be uploaded.
#

# Devices and ports etc.
#
# AVR device:
AVR=atmega328p

# ICSP device:
ICSP=usbtiny

# programs and config files
#
# Where everything lives:
ARDUINO_HOME="${HOME}"/.arduino15
AVRDUDE_TOOLS="${ARDUINO_HOME}"/packages/arduino/tools
AVRDUDE_HOME="${AVRDUDE_TOOLS}"/avrdude/6.3.0-arduino17

# Avrdude executable:
AVRDUDE="${AVRDUDE_HOME}"/bin/avrdude

# Avrdude configuration file:
AVRDUDECONF="${AVRDUDE_HOME}"/etc/avrdude.conf

# Leave blank if you don't want all the output.
# Otherwise, use -v
VERBOSE=-v

# Get hex file.
HEXFILE="${1}"

# Did we get a parameter?
if [ "${HEXFILE}" == "" ]
then
    echo A hex filename must be passed.
    exit 1
fi

# Does the file exist?
if ([ ! -f "${HEXFILE}" ])
then
    echo "${HEXFILE}" is not a filename.
    exit 1
fi

# Does the file have the 'hex' extension?
EXTENSION="${HEXFILE##*.}"
if [ "${EXTENSION}" != "hex" ]
then
    echo "${HEXFILE}" is not a valid compiled Arduino sketch
    exit 1
fi

# Upload via the ICSP device.
echo "${AVRDUDE}" -C "${AVRDUDECONF}" "${VERBOSE}" \
     -p "${AVR}" -c "${ICSP}" -Uflash:w:"${HEXFILE}":i 

"${AVRDUDE}" -C "${AVRDUDECONF}" "${VERBOSE}" \
     -p "${AVR}" -c "${ICSP}" -Uflash:w:"${HEXFILE}":i 
