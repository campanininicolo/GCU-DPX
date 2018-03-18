#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/sensors.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/sensors.h"
#line 22 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/sensors.h"
void Sensors_init(void);

void Sensors_tick(void);

void Sensors_read(void);

void Sensors_nextPin(void);

void Sensors_send(void);

void Sensors_sampleFanCurrent(unsigned int value);

void Sensors_sampleH2OPumpCurrent(unsigned int value);

void Sensors_sampleFuelPumpCurrent(unsigned int value);

void Sensors_sampleGCUTemp(unsigned int value);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/sensors.c"
const unsigned char SENSORS[] = {
  AN5 ,
  AN4 ,
  AN3 ,
  AN2 
};

unsigned char sensors_pinIndex = 0;

unsigned int sensors_fanCurrent,
 sensors_H2OPumpCurrent,
 sensors_fuelPumpCurrent,
 sensors_GCUTemp;

unsigned int sensors_H2OSamples = 0,
 sensors_fuelPumpSamples = 0,
 sensors_maxRecordedH2OCurrent = 0,
 sensors_maxRecordedFuelPumpCurrent = 0;

void Sensors_init(void) {
 setupAnalogSampling();
 setAnalogPIN(SENSORS[sensors_pinIndex]);
 turnOnAnalogModule();
}

void Sensors_send(void) {
 Can_resetWritePacket();
 Can_addIntToWritePacket(sensors_fanCurrent);
 Can_addIntToWritePacket(sensors_fuelPumpCurrent);
 Can_addIntToWritePacket(sensors_GCUTemp);
 Can_addIntToWritePacket(sensors_H2OPumpCurrent);
 Can_write(GCU_SENSE_ID);
}

void Sensors_tick(void) {
 Sensors_read();
 Sensors_nextPin();
}

void Sensors_read(void) {
 unsigned int analogValue;
 analogValue = getAnalogValue();
 switch (SENSORS[sensors_pinIndex]) {
 case  AN5 :
 Sensors_sampleFanCurrent(analogValue);
 break;
 case  AN4 :
 Sensors_sampleH2OPumpCurrent(analogValue);
 break;
 case  AN3 :
 Sensors_sampleFuelPumpCurrent(analogValue);
 break;
 case  AN2 :
 Sensors_sampleGCUTemp(analogValue);
 break;
 default:
 break;
 }
}

void Sensors_nextPin(void) {
 unsetAnalogPIN(SENSORS[sensors_pinIndex]);
 sensors_pinIndex += 1;
 if (sensors_pinIndex == sizeof(SENSORS)) {
 sensors_pinIndex = 0;
 }
 setAnalogPIN(SENSORS[sensors_pinIndex]);
}

void Sensors_sampleFanCurrent(unsigned int value) {
 sensors_fanCurrent = sensors_fanCurrent * 0.95 + value * 0.05;
}

void Sensors_sampleH2OPumpCurrent(unsigned int value) {
#line 92 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/sensors.c"
 sensors_H2OPumpCurrent = sensors_H2OPumpCurrent * 0.95 + value * 0.05;
}

void Sensors_sampleFuelPumpCurrent(unsigned int value) {
#line 107 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/sensors.c"
 sensors_fuelPumpCurrent = sensors_fuelPumpCurrent * 0.95 + value * 0.05;
}

void Sensors_sampleGCUTemp(unsigned int value) {
 sensors_GCUTemp = sensors_GCUTemp * 0.95 + value * 0.05;
}
