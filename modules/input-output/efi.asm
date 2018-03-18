
_Efi_init:

;efi.c,7 :: 		void Efi_init(void) {
;efi.c,8 :: 		DOWNCUT_Direction = OUTPUT;
	BCLR	TRISD2_bit, BitPos(TRISD2_bit+0)
;efi.c,9 :: 		UPCUT_Direction = OUTPUT;
	BCLR	TRISD3_bit, BitPos(TRISD3_bit+0)
;efi.c,10 :: 		RPM_LIMITER_Direction = OUTPUT;
	BCLR	TRISD4_bit, BitPos(TRISD4_bit+0)
;efi.c,11 :: 		RPM_LIMITER_Pin = 0;
	BCLR	RD4_bit, BitPos(RD4_bit+0)
;efi.c,12 :: 		Efi_unsetBlip();
	CALL	_Efi_unsetBlip
;efi.c,13 :: 		Efi_unsetCut();
	CALL	_Efi_unsetCut
;efi.c,14 :: 		Efi_unsetRPMLimiter();
	CALL	_Efi_unsetRPMLimiter
;efi.c,15 :: 		}
L_end_Efi_init:
	RETURN
; end of _Efi_init

_Efi_setCut:

;efi.c,17 :: 		void Efi_setCut(void) {
;efi.c,18 :: 		UPCUT_Pin = SET_CUT;
	BCLR	RD3_bit, BitPos(RD3_bit+0)
;efi.c,19 :: 		}
L_end_Efi_setCut:
	RETURN
; end of _Efi_setCut

_Efi_unsetCut:

;efi.c,21 :: 		void Efi_unsetCut(void) {
;efi.c,22 :: 		UPCUT_Pin = UNSET_CUT;
	BSET	RD3_bit, BitPos(RD3_bit+0)
;efi.c,23 :: 		}
L_end_Efi_unsetCut:
	RETURN
; end of _Efi_unsetCut

_Efi_setBlip:

;efi.c,25 :: 		void Efi_setBlip(void) {
;efi.c,26 :: 		DOWNCUT_Pin = SET_CUT;
	BCLR	RD2_bit, BitPos(RD2_bit+0)
;efi.c,27 :: 		}
L_end_Efi_setBlip:
	RETURN
; end of _Efi_setBlip

_Efi_unsetBlip:

;efi.c,29 :: 		void Efi_unsetBlip(void) {
;efi.c,30 :: 		DOWNCUT_Pin = UNSET_CUT;
	BSET	RD2_bit, BitPos(RD2_bit+0)
;efi.c,31 :: 		}
L_end_Efi_unsetBlip:
	RETURN
; end of _Efi_unsetBlip

_Efi_setRPMLimiter:

;efi.c,33 :: 		void Efi_setRPMLimiter(void){
;efi.c,34 :: 		RPM_LIMITER_Pin = SET_RPM_LIMITER;
	BCLR	RD4_bit, BitPos(RD4_bit+0)
;efi.c,35 :: 		}
L_end_Efi_setRPMLimiter:
	RETURN
; end of _Efi_setRPMLimiter

_Efi_unsetRPMLimiter:

;efi.c,37 :: 		void Efi_unsetRPMLimiter(void){
;efi.c,38 :: 		RPM_LIMITER_Pin = UNSET_RPM_LIMITER;
	BSET	RD4_bit, BitPos(RD4_bit+0)
;efi.c,39 :: 		}
L_end_Efi_unsetRPMLimiter:
	RETURN
; end of _Efi_unsetRPMLimiter
