#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/stoplight.c"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/stoplight.h"
#line 17 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/stoplight.h"
void StopLight_init(void);

void StopLight_setupPWM(void);

void StopLight_setBrightness(unsigned char percentage);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/stoplight.c"
unsigned int STOPLIGHT_PWM_PERIOD_VALUE;
double STOPLIGHT_PERCENTAGE_STEP;
unsigned int STOPLIGHT_PWM_VALUE;

void StopLight_init(void) {
 StopLight_setupPWM();
}

void StopLight_setupPWM(void) {
 OC7CON = 0x6;
 STOPLIGHT_PWM_PERIOD_VALUE = getTimerPeriod( 0.020 , TIMER2_PRESCALER);
 STOPLIGHT_PWM_VALUE = (unsigned int) (STOPLIGHT_PWM_PERIOD_VALUE *
 ( 95  / 100.0));
 OC7R = STOPLIGHT_PWM_VALUE;
 OC7RS = STOPLIGHT_PWM_VALUE;
}

void StopLight_setBrightness(unsigned char percentage) {
 unsigned int pwmValue;
 pwmValue = (unsigned int) (STOPLIGHT_PWM_PERIOD_VALUE * (percentage / 100.0));
 if (pwmValue > 100) {
 pwmValue = (unsigned int) STOPLIGHT_PWM_PERIOD_VALUE;
 } else if (pwmValue < 0) {
 pwmValue = 1;
 }
 OC7RS = pwmValue;
}
