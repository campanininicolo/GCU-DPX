#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/libs/basic.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for dspic/include/stdio.h"
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/libs/basic.h"
#line 16 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/libs/basic.h"
void unsignedIntToString(unsigned int number, char *text);

void signedIntToString(int number, char *text);

unsigned char getNumberDigitCount(unsigned char number);

void emptyString(char* myString);
#line 8 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/libs/basic.c"
void unsignedIntToString(unsigned int number, char *text) {
 emptyString(text);
 sprintf(text, "%u", number);
}

void signedIntToString(int number, char *text) {
 emptyString(text);
 sprintf(text, "%d", number);
}

void emptyString(char *myString) {
 myString[0] = '\0';
#line 23 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/libs/basic.c"
}

unsigned char getNumberDigitCount(unsigned char number) {
 if (number >= 100) {
 return 3;
 } else if (number >= 10) {
 return 2;
 } else {
 return 1;
 }
}
