#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/aac/aac.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/aac/aac.h"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/aac/aac_defaults.h"
#line 27 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/aac/aac.h"
typedef enum{
 OFF,
 START,
 READY,
 START_RELEASE,
 RELEASING,
 RUNNING,
 STOPPING
}aac_states;


typedef enum{
 RAMP_START,
 RAMP_END,
 RAMP_TIME,

 RPM_LIMIT_1_2,
 RPM_LIMIT_2_3,
 RPM_LIMIT_3_4,
 SPEED_LIMIT_1_2,
 SPEED_LIMIT_2_3,
 SPEED_LIMIT_3_4
}aac_params;

typedef enum{
 MEX_ON,
 MEX_READY,
 MEX_GO,
 MEX_OFF,
}aac_notifications;


typedef enum{
 RPM,
 WHEEL_SPEED,
 APPS
}aac_values;

extern unsigned int gearShift_currentGear;

void aac_init(void);


void aac_execute(void);


void aac_checkAndPrepare(void);

void aac_stop(void);

void aac_loadDefaultParams(void);

void aac_updateParam(const aac_params id, const int value);

void aac_updateExternValue(const aac_values id, const int value);

int aac_getParam(const aac_params id);

int aac_getExternValue(const aac_values id);

void aac_forceState(const aac_states newState);

void aac_sendTimes(void);

void aac_sendOneTime(time_id pos);

void aac_sendAllTimes(void);
#line 3 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/aac/aac.c"
aac_states aac_currentState;
int aac_parameters[ 9 ];
int aac_externValues[ 3 ];
int aac_dtRelease;
char aac_sendingAll = FALSE;
int aac_timesCounter;
#line 15 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/aac/aac.c"
float aac_clutchStep;
float aac_clutchValue;


void aac_init(void){
 aac_currentState = OFF;
 aac_loadDefaultParams();
}

void aac_execute(void){
 switch (aac_currentState) {
 case START:
 Efi_setRPMLimiter();

 Can_writeByte(SW_AUX_ID, MEX_READY);
 aac_currentState = READY;
 aac_clutchValue = 100;
 Clutch_set((unsigned int)aac_clutchValue);
 return;
 case READY:
 Clutch_set(100);
 return;
 case START_RELEASE:
 aac_clutchValue = aac_parameters[RAMP_START];
 Clutch_set(aac_clutchValue);
 aac_dtRelease = aac_parameters[RAMP_TIME] /  25 ;
 aac_clutchStep = ((float)(aac_parameters[RAMP_START] - aac_parameters[RAMP_END]) *  25 ) / (float)aac_parameters[RAMP_TIME];
 aac_currentState = RELEASING;
 return;
 case RELEASING:

 aac_clutchValue = aac_clutchValue - aac_clutchStep;
 Clutch_set((unsigned char)aac_clutchValue);
 aac_dtRelease--;
 if(aac_dtRelease <= 0 || Clutch_get() <= aac_parameters[RAMP_END]){
 Clutch_set(0);
 Efi_unsetRPMLimiter();
 aac_currentState = RUNNING;


 }
 Buzzer_bip();
 return;
 case RUNNING:

 if(gearShift_currentGear == 4){
 aac_stop();
 return;
 }

 if(aac_externValues[RPM] >= aac_parameters[RPM_LIMIT_1_2 + gearShift_currentGear - 1]
 && aac_externValues[WHEEL_SPEED] >= aac_parameters[SPEED_LIMIT_1_2 + gearShift_currentGear - 1]){
 GearShift_up();
 }
 return;
 case STOPPING:
 aac_currentState = OFF;
 Can_writeByte(SW_AUX_ID, MEX_OFF);
 return;

 default: return;
 }
}

void aac_sendOneTime(time_id pos){
 aac_timesCounter = pos;
}

void aac_sendTimes(void)
{
 if(aac_timesCounter >= 0){
 Can_resetWritePacket();
 Can_addIntToWritePacket( 2 );
 Can_addIntToWritePacket(aac_timesCounter);
 Can_addIntToWritePacket(aac_parameters[aac_timesCounter]);
 if(Can_write(CAN_ID_TIMES) < 0)
 Buzzer_Bip();
 aac_timesCounter -= 1;
 if(!aac_sendingAll || aac_timesCounter < 0){
 aac_sendingAll = FALSE;
 aac_timesCounter = -1;
 }
 }
}

void aac_sendAllTimes(void)
{
 if(!aac_sendingAll){
 aac_timesCounter =  9 ;
 aac_sendingAll = TRUE;
 }
}

void aac_loadDefaultParams(void){


 aac_parameters[RAMP_START] =  70 ;
 aac_parameters[RAMP_END] =  0 ;
 aac_parameters[RAMP_TIME] =  250 ;
 aac_parameters[RPM_LIMIT_1_2] =  11300 ;
 aac_parameters[RPM_LIMIT_2_3] =  11300 ;
 aac_parameters[RPM_LIMIT_3_4] =  11300 ;
 aac_parameters[SPEED_LIMIT_1_2] =  47 ;
 aac_parameters[SPEED_LIMIT_2_3] =  65 ;
 aac_parameters[SPEED_LIMIT_3_4] =  80 ;

}

void aac_updateParam(const aac_params id, const int value){
 if(id <  9 )
 aac_parameters[id] = value;
}

void aac_stop(void){
 if(aac_currentState != OFF)
 aac_currentState = STOPPING;
}

void aac_updateExternValue(const aac_values id, const int value){
 if(id <  3 )
 aac_externValues[id] = value;
}

int aac_getParam(const aac_params id){
 if(id <  9 )
 return aac_parameters[id];
 return -1;
}

int aac_getExternValue(const aac_params id){
 if(id <  3 )
 return aac_externValues[id];
 return -1;
}
