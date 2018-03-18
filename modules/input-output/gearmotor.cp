#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/gearmotor.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/gearmotor.h"
#line 26 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/gearmotor.h"
void GearMotor_init(void);

void GearMotor_turnLeft(void);

void GearMotor_turnRight(void);

void GearMotor_brake(void);

void GearMotor_release(void);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/gearmotor.c"
void GearMotor_init(void) {
  TRISB0_bit  = OUTPUT;
  TRISC1_bit  = OUTPUT;
  TRISB1_bit  = OUTPUT;
 GearMotor_release();
}

void GearMotor_turnLeft(void) {
  LATB0_bit  = 0;
  LATC1_bit  = 1;
  LATB1_bit  = 1;
}

void GearMotor_turnRight(void) {
  LATB0_bit  = 1;
  LATC1_bit  = 0;
  LATB1_bit  = 1;
}

void GearMotor_brake(void) {
  LATB0_bit  = 0;
  LATC1_bit  = 0;
  LATB1_bit  = 1;
}

void GearMotor_release(void) {
  LATB1_bit  = 0;
}
