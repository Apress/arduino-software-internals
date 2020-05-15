#!/bin/bash
#
# A script to program a Duemilanove with the default Arduino
# bootloader and fuses. The script assumes that the device 
# is indeed a Duemilanove, that the default bootloader hex
# file exists and that a USBtiny programmer will be used. 
#
# You CANNOT burn a bootloader using the current bootloader!
#
# Run the "burn bootloader" command in the IDE, for your
# device, with verbose upload configured to see your command
# line, and change the necessary variables below.
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

# The following long path is split on two lines. There
# are no leading or trailing spaces on each line.
BOOTLOADER_HOME="${ARDUINO_HOME}"/packages/arduino/\
hardware/avr/1.8.2/bootloaders/atmega

# Avrdude executable:
AVRDUDE="${AVRDUDE_HOME}"/bin/avrdude

# Avrdude configuration file:
AVRDUDECONF="${AVRDUDE_HOME}"/etc/avrdude.conf

# Leave blank if you don't want all the output.
# Otherwise, use -v
VERBOSE=-v

# Bootloader details:
BOOTLOADER="${BOOTLOADER_HOME}"/ATmegaBOOT_168_atmega328.hex

# Fuses: 
EFUSE=0xFD
HFUSE=0xDA
LFUSE=0xFF

LOCK=0x0F
UNLOCK=0x3F

# Does the bootloader file exist?
if ([ ! -f "${BOOTLOADER}" ])
then
    echo "${BOOTLOADER}" is not a valid filename.
    exit 1
fi

# Does the bootloader file have the 'hex' extension?
EXTENSION="${BOOTLOADER##*.}"
if [ "${EXTENSION}" != "hex" ]
then
    echo "${BOOTLOADER}" is not a valid compiled Arduino bootloader file
    exit 1
fi

# Set the fuses for a Duemilanove.
${AVRDUDE}" -C ${AVRDUDECONF}" "${VERBOSE}" \
-p "${AVR}" -c "${ICSP}" -e -Ulock:w:"${UNLOCK}":m \
-Uefuse:w:"${EFUSE}":m -Uhfuse:w:"${HFUSE}":m \
-Ulfuse:w:"${LFUSE}":m 

# Burn the actual bootloader hex file.
"${AVRDUDE}" -C "${AVRDUDECONF}" "${VERBOSE}" \
-p "${AVR}" -c "${ICSP}" -Uflash:w:"${BOOTLOADER}":i \
-Ulock:w:"${LOCK}":m 
