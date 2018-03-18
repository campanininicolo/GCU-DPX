#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/buzzer.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/buzzer.h"
#line 17 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/buzzer.h"
void Buzzer_init(void);

void Buzzer_tick(void);

void Buzzer_Bip(void);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/buzzer.c"
unsigned int buzzer_ticks = 0, buzzer_bipTicks;

onTimer4Interrupt{
 clearTimer4();
 Buzzer_tick();
}

void Buzzer_init(void) {
  TRISG13_bit  = OUTPUT;
  RG13_bit  = 0;
 setTimer(TIMER4_DEVICE,  0.0005 );
 setInterruptPriority(TIMER4_DEVICE, LOW_PRIORITY);
 buzzer_bipTicks = (int)( 1  /  0.0005 );
}

void Buzzer_tick(void) {
 if (buzzer_ticks > 0) {
 buzzer_ticks -= 1;
  RG13_bit  = ! RG13_bit ;
 }
 else
  RG13_bit  = 0;
}

void Buzzer_Bip(void) {
 buzzer_ticks = buzzer_bipTicks;
}
