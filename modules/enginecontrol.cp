#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/enginecontrol.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/enginecontrol.h"
#line 30 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/enginecontrol.h"
void EngineControl_init(void);

void EngineControl_keyOn(void);

void EngineControl_keyOff(void);

void EngineControl_start(void);

void EngineControl_stop(void);

void EngineControl_resetStartCheck(void);

char EngineControl_isStarting(void);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/enginecontrol.c"
unsigned char engineControl_isChecking;
unsigned char engineControl_startCheckCounter;

void EngineControl_init(void) {
  TRISD.B5  = OUTPUT;
  TRISD.B1  = OUTPUT;
  TRISG.B15  = OUTPUT;

  LATD1_bit  =  1 ;
  RG15_bit  =  1 ;
 engineControl_isChecking = FALSE;
 EngineControl_resetStartCheck();
 EngineControl_stop();
}


void EngineControl_keyOn(void) {
  RG15_bit  =  1 ;
}


void EngineControl_keyOff(void) {
  RG15_bit  =  0 ;
}

void EngineControl_start(void) {
 dSignalLed_set(DSIGNAL_LED_RG12);
  LATD5_bit  = TRUE;
}

void EngineControl_stop(void) {
 dSignalLed_unset(DSIGNAL_LED_RG12);
  LATD5_bit  = FALSE;
}

void EngineControl_resetStartCheck(void) {
 engineControl_startCheckCounter = 0;
}

char EngineControl_isStarting(void) {
 if (engineControl_startCheckCounter <  4 ) {
 engineControl_startCheckCounter += 1;
 return TRUE;
 } else {
 return FALSE;
 }
}
