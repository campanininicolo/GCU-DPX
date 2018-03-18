#line 1 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/efi.c"
ppèòàù
#line 1 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/efi.h"
#line 23 "d:/google drive/reparto elettronica 2017/gcu/dy_gcu_austria_2017/modules/input-output/efi.h"
void Efi_init(void);

void Efi_setCut(void);

void Efi_unsetCut(void);

void Efi_setBlip(void);

void Efi_unsetBlip(void);

void Efi_setRPMLimiter(void);

void Efi_unsetRPMLimiter(void);

void Efi_setRPMLimiter_CAN(unsigned int limit);

void Efi_unsetRPMLimiter_CAN(unsigned int limit);
#line 7 "D:/Google Drive/REPARTO ELETTRONICA 2017/GCU/DY_GCU_AUSTRIA_2017/modules/input-output/efi.c"
void Efi_init(void) {
  TRISD2_bit  = OUTPUT;
  TRISD3_bit  = OUTPUT;
  TRISD4_bit  = OUTPUT;
  RD4_bit  = 0;
 Efi_unsetBlip();
 Efi_unsetCut();
 Efi_unsetRPMLimiter();
}

void Efi_setCut(void) {
  RD3_bit  =  0 ;
}

void Efi_unsetCut(void) {
  RD3_bit  =  1 ;
}

void Efi_setBlip(void) {
  RD2_bit  =  0 ;
}

void Efi_unsetBlip(void) {
  RD2_bit  =  1 ;
}

void Efi_setRPMLimiter(void){
  RD4_bit  =  0 ;
}

void Efi_unsetRPMLimiter(void){
  RD4_bit  =  1 ;
}
