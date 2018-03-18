#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/clutch.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/clutch.h"
#line 14 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/clutch.h"
void Clutch_insert(void);

void Clutch_release(void);

void Clutch_set(unsigned char percentage);

unsigned char Clutch_get(void);

void Clutch_setBiased(unsigned char value);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/clutch.c"
unsigned char Clutch_currentValue = 0;

void Clutch_insert(void) {
 Clutch_set(100);
}

void Clutch_release(void) {
 Clutch_set(0);
}

void Clutch_set(unsigned char percentage) {
 unsigned char actualPercentage = 0;
 if (percentage > 100) {
 actualPercentage = 100;
 } else {
 actualPercentage = percentage;
 }
 ClutchMotor_setPosition(100 - actualPercentage);
 Clutch_currentValue = actualPercentage;
}

unsigned char Clutch_get(void) {
 return Clutch_currentValue;
}

void Clutch_setBiased(unsigned char value){
 int actual_value;
 if(value >=  95 )
 Clutch_set(value);
 else{
 actual_value = ( 70  * value) / 100;
 Clutch_set(actual_value);
 }
}
