#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/clutchmotor.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/clutchmotor.h"
#line 16 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/clutchmotor.h"
void ClutchMotor_init(void);

void ClutchMotor_setupPWM(void);

void ClutchMotor_setPosition(unsigned char percentage);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/clutchmotor.c"
unsigned int CLUTCHMOTOR_PWM_PERIOD_VALUE;
double CLUTCHMOTOR_PERCENTAGE_STEP;
unsigned int CLUTCHMOTOR_PWM_MAX_VALUE;
unsigned int CLUTCHMOTOR_PWM_MIN_VALUE;

onTimer2Interrupt{
 clearTimer2();
}

void ClutchMotor_init(void) {
 setTimer(TIMER2_DEVICE,  0.020 );
 ClutchMotor_setupPWM();
}

void ClutchMotor_setupPWM(void) {
 OC8CON = 0x6;
 CLUTCHMOTOR_PWM_PERIOD_VALUE = getTimerPeriod( 0.020 , TIMER2_PRESCALER);

 CLUTCHMOTOR_PWM_MAX_VALUE = (unsigned int) (CLUTCHMOTOR_PWM_PERIOD_VALUE *
 ( 11  / 100.0));
 CLUTCHMOTOR_PWM_MIN_VALUE = (unsigned int) (CLUTCHMOTOR_PWM_PERIOD_VALUE *
 ( 5  / 100.0));
 CLUTCHMOTOR_PERCENTAGE_STEP = (CLUTCHMOTOR_PWM_MAX_VALUE - CLUTCHMOTOR_PWM_MIN_VALUE) / 100.0;
 OC8R = CLUTCHMOTOR_PWM_MIN_VALUE;
 ClutchMotor_setPosition(100);
}

void ClutchMotor_setPosition(unsigned char percentage) {
 unsigned int pwmValue;
 pwmValue = (unsigned int) ((percentage * CLUTCHMOTOR_PERCENTAGE_STEP) + CLUTCHMOTOR_PWM_MIN_VALUE);
 if (pwmValue > CLUTCHMOTOR_PWM_MAX_VALUE) {
 pwmValue = CLUTCHMOTOR_PWM_MAX_VALUE;
 } else if (pwmValue < CLUTCHMOTOR_PWM_MIN_VALUE) {
 pwmValue = CLUTCHMOTOR_PWM_MIN_VALUE;
 }
 OC8RS = pwmValue;
}
