#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/gcu_rio.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/gcu_rio.h"
#line 41 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/gcu_rio.h"
typedef enum {

 NT_PUSH_1_N,
 NT_CLUTCH_1_N,
 NT_REBOUND_1_N,
 NT_BRAKE_1_N,

 NT_PUSH_2_N,
 NT_CLUTCH_2_N,
 NT_REBOUND_2_N,
 NT_BRAKE_2_N,

 DN_PUSH,
 CLUTCH,
 DN_REBOUND,
 DN_BRAKE,

 UP_PUSH_1_2,
 UP_PUSH_2_3,
 UP_PUSH_3_4,
 UP_PUSH_4_5,

 DELAY,
 UP_REBOUND,
 UP_BRAKE,

 NT_CLUTCH_DELAY,


 DOWN_TIME_CHECK,
 UP_TIME_CHECK,
 MAX_TRIES,


 TIMES_LAST
 }time_id;

 typedef enum{

 H2O_DC,
 TH2O_ENGINE,
 TH2O_IN,
 TH2O_OUT,

 POIL,
 TOIL_IN,
 TOIL_OUT,
 BATTERY,

 P_FUEL,
 FAN,
 INJ1,
 INJ2,

 DATA_LAST
 }efi_dataIds;




extern unsigned int gearShift_timings[ TIMES_LAST ];

void rio_init(void);

extern void rio_sendOneTime(time_id pos);

extern void rio_sendAllTimes(void);

extern void rio_sendTimes(void);

extern void rio_send(void);
#line 3 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/gcu_rio.c"
char rio_sendingAll = FALSE;
int rio_timesCounter;
int timer1_rioEfiCounter;
int rio_efiData[ DATA_LAST ];
int rio_canId;

void rio_init(void){
 rio_canId = CAN_ID_DATA_1;
}

void rio_sendOneTime(time_id pos){
 rio_timesCounter = pos;
}

void rio_sendTimes(void)
{
 if(rio_timesCounter >= 0){
 Can_resetWritePacket();
 Can_addIntToWritePacket( 0 );
 Can_addIntToWritePacket(rio_timesCounter);
 Can_addIntToWritePacket(gearShift_timings[rio_timesCounter]);
 if(Can_write(CAN_ID_TIMES) < 0)
 Buzzer_Bip();
 rio_timesCounter -= 1;
 if(!rio_sendingAll || rio_timesCounter < 0){
 rio_sendingAll = FALSE;
 rio_timesCounter = -1;
 }
 }
}

void rio_sendAllTimes(void)
{
 if(!rio_sendingAll){
 rio_timesCounter =  TIMES_LAST ;
 rio_sendingAll = TRUE;
 }
}

void rio_send(void){
 switch(rio_canId){
 case CAN_ID_DATA_1:
 Can_resetWritePacket();
 Can_addIntToWritePacket(rio_efiData[H2O_DC]);
 Can_addIntToWritePacket(rio_efiData[TH2O_ENGINE]);
 Can_addIntToWritePacket(rio_efiData[TH2O_IN]);
 Can_addIntToWritePacket(rio_efiData[TH2O_OUT]);
 Can_write(rio_canId);
 rio_canId = CAN_ID_DATA_2;
 break;
 case CAN_ID_DATA_2:
 Can_resetWritePacket();
 Can_addIntToWritePacket(rio_efiData[POIL]);
 Can_addIntToWritePacket(rio_efiData[TOIL_IN]);
 Can_addIntToWritePacket(rio_efiData[TOIL_OUT]);
 Can_addIntToWritePacket(rio_efiData[BATTERY]);
 Can_write(rio_canId);
 rio_canId = CAN_ID_DATA_3;
 break;
 case CAN_ID_DATA_3:
 Can_resetWritePacket();
 Can_addIntToWritePacket(rio_efiData[P_FUEL]);
 Can_addIntToWritePacket(rio_efiData[FAN]);
 Can_addIntToWritePacket(rio_efiData[INJ1]);
 Can_addIntToWritePacket(rio_efiData[INJ2]);
 Can_write(rio_canId);
 rio_canId = CAN_ID_DATA_1;
 break;
 }
}
