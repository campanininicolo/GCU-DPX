#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/libs/eeprom.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/libs/eeprom.h"







void EEPROM_writeInt(unsigned int address, unsigned int value);

unsigned int EEPROM_readInt(unsigned int address);

void EEPROM_writeArray(unsigned int address, unsigned int *values);

void EEPROM_readArray(unsigned int address, unsigned int *values);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/libs/eeprom.c"
void EEPROM_writeInt(unsigned int address, unsigned int value) {
 unsigned int currentValue;
 currentValue = EEPROM_read(address);
 if (currentValue != value) {
 EEPROM_write(address, value);
 }
}

unsigned int EEPROM_readInt(unsigned int address) {
 return EEPROM_read(address);
}

void EEPROM_writeArray(unsigned int address, unsigned int *values) {
 unsigned int i;
 for (i = 0; i < sizeof(values); i += 1) {
 EEPROM_writeInt(address, values[i]);
 }
}

void EEPROM_readArray(unsigned int address, unsigned int *values) {
 unsigned int i;
 for (i = 0; i < sizeof(values); i += 1) {
 values[i] = EEPROM_read(address + i);
 }
}
