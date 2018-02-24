# SPI-EEPROM-AVR

This is a simple project in which a EEPROM chip that can hold 256 bytes of data is programmed using a ATMEGA328p chip and read back the contents from the locations which was written to. 
The SCK frequency in use is 1MHz which enables really fast (in comparison to USART or I2C) transfer of data, 8us per byte. 

The preprogrammed bytes are written and read back and given out on serial line.
