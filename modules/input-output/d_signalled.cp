#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/d_signalled.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/d_signalled.h"
#line 26 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/d_signalled.h"
void dSignalLed_init(void);

void dSignalLed_switch(unsigned char led);

void dSignalLed_set(unsigned char led);

void dSignalLed_unset(unsigned char led);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/d_signalled.c"
void dSignalLed_init(void) {
  TRISG14_bit  = OUTPUT;
  TRISG12_bit  = OUTPUT;
 dSignalLed_unset( 0 );
 dSignalLed_unset( 1 );
}

void dSignalLed_switch(unsigned char led) {
 switch (led) {
 case  0 :
  RG14_bit  = ! RG14_bit ;
 break;
 case  1 :
  RG12_bit  = ! RG12_bit ;
 break;
 }
}

void dSignalLed_set(unsigned char led) {
 switch (led) {
 case  0 :
  RG14_bit  =  1 ;
 break;
 case  1 :
  RG12_bit  =  1 ;
 break;
 }
}

void dSignalLed_unset(unsigned char led) {
 switch (led) {
 case  0 :
  RG14_bit  =  0 ;
 break;
 case  1 :
  RG12_bit  =  0 ;
 break;
 }
}
