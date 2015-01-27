
;; MC56F827xx_init.inc
;; Copyright Freescale Semiconductor Inc. 2012



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Operating Mode Register (OMR) Bitmasks
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 set OMR_NL          BIT15           ;; Nested Loop
 set OMR_CM          BIT8            ;; Condition Code Mode
 set OMR_XP          BIT7            ;; X or P Execute
 set OMR_SD          BIT6            ;; Stop Delay
 set OMR_R           BIT5            ;; Rounding
 set OMR_SA          BIT4            ;; Saturation Mode
 set OMR_EX          BIT3            ;; External Data Memory
 set OMR_MB          BIT1            ;; Mode B (Flash Security)
 set OMR_MA          BIT0            ;; Mode A (Extboot)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Status Register (SR) Bitmasks
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 set SR_LF   BIT15           ;; Loop Flag
 set SR_P    $7C00           ;; Program Counter Extension
 set SR_P4   BIT14           ;; Program Counter Extension[4]
 set SR_P3   BIT13           ;; Program Counter Extension[3]
 set SR_P2   BIT12           ;; Program Counter Extension[2]
 set SR_P1   BIT11           ;; Program Counter Extension[1]
 set SR_P0   BIT10           ;; Program Counter Extension[0]
 set SR_I    (BIT9+BIT8)     ;; Interrupt Mask
 set SR_I1   BIT9            ;; Interrupt Mask[1]
 set SR_I0   BIT8            ;; Interrupt Mask[0]
 set SR_SZ   BIT7            ;; Size
 set SR_L    BIT6            ;; Limit
 set SR_E    BIT5            ;; Extension In Use
 set SR_U    BIT4            ;; Un-normalized
 set SR_N    BIT3            ;; Negative
 set SR_Z    BIT2            ;; Zero
 set SR_V    BIT1            ;; Overflow
 set SR_C    BIT0            ;; Carry


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Interrupt Priority Level (IPL) Bitmasks
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 set IPL0    (0)             ;; Enable IPL0, IPL1, IPL2, IPL3
 set IPL1    (SR_I0)         ;; Enable IPL1, IPL2, IPL3
 set IPL2    (SR_I1)         ;; Enable IPL2, IP3
 set IPL3    (SR_I1+SR_I0)   ;; Enable IPL3

