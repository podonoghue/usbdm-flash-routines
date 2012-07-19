/*
 * File:    exceptions.c
 * Purpose: Generic exception handling for ColdFire processors
 *
 */
#include <cstdint>

void isr_default(void);
asm void asm_testApp(void);
extern uint8_t _stacktop[];
extern uint8_t gFlashProgramHeader[];

typedef void (* vectorTableEntryType)(void);

#pragma define_section vectortable ".vectortable" far_absolute R

/* CF processors have 255 vector + SP_INIT in the vector table (256 entries)
*/  
__declspec(vectortable) vectorTableEntryType _vect[256] = {   /* Interrupt vector table */
   (vectorTableEntryType)gFlashProgramHeader, /*   0 (0x000) Point to data structure      */
   asm_testApp,                               /*   1 (0x004) Initial PC                 */
   isr_default,                               /*   2 (0x008) Access Error               */
   isr_default,                               /*   3 (0x00C) Address Error              */
   isr_default,                               /*   4 (0x010) Illegal Instruction        */
   isr_default,                               /*   5 (0x014) Reserved                   */
   isr_default,                               /*   6 (0x018) Reserved                   */
   isr_default,                               /*   7 (0x01C) Reserved                   */
   isr_default,                               /*   8 (0x020) Privilege Violation        */
   isr_default,                               /*   9 (0x024) Trace                      */
   isr_default,                               /*  10 (0x028) Unimplemented A-Line       */
   isr_default,                               /*  11 (0x02C) Unimplemented F-Line       */
   isr_default,                               /*  12 (0x030) Debug Interrupt            */
   isr_default,                               /*  13 (0x034) Reserved                   */
   isr_default,                               /*  14 (0x038) Format Error               */
   isr_default,                               /*  15 (0x03C) Unitialized Int            */
   isr_default,                               /*  16 (0x040) Reserved                   */
   isr_default,                               /*  17 (0x044) Reserved                   */
   isr_default,                               /*  18 (0x048) Reserved                   */
   isr_default,                               /*  19 (0x04C) Reserved                   */
   isr_default,                               /*  20 (0x050) Reserved                   */
   isr_default,                               /*  21 (0x054) Reserved                   */
   isr_default,                               /*  22 (0x058) Reserved                   */
   isr_default,                               /*  23 (0x05C) Reserved                   */
   isr_default,                               /*  24 (0x060) Spurious Interrupt         */
   isr_default,                               /*  25 (0x064) Autovector Level 1         */
   isr_default,                               /*  26 (0x068) Autovector Level 2         */
   isr_default,                               /*  27 (0x06C) Autovector Level 3         */
   isr_default,                               /*  28 (0x070) Autovector Level 4         */
   isr_default,                               /*  29 (0x074) Autovector Level 5         */
   isr_default,                               /*  30 (0x078) Autovector Level 6         */
   isr_default,                               /*  31 (0x07C) Autovector Level 7         */
   isr_default,                               /*  32 (0x080) TRAP #0                    */
   isr_default,                               /*  33 (0x084) TRAP #1                    */
   isr_default,                               /*  34 (0x088) TRAP #2                    */
   isr_default,                               /*  35 (0x08C) TRAP #3                    */
   isr_default,                               /*  36 (0x090) TRAP #4                    */
   isr_default,                               /*  37 (0x094) TRAP #5                    */
   isr_default,                               /*  38 (0x098) TRAP #6                    */
   isr_default,                               /*  39 (0x09C) TRAP #7                    */
   isr_default,                               /*  40 (0x0A0) TRAP #8                    */
   isr_default,                               /*  41 (0x0A4) TRAP #9                    */
   isr_default,                               /*  42 (0x0A8) TRAP #10                   */
   isr_default,                               /*  43 (0x0AC) TRAP #11                   */
   isr_default,                               /*  44 (0x0B0) TRAP #12                   */
   isr_default,                               /*  45 (0x0B4) TRAP #13                   */
   isr_default,                               /*  46 (0x0B8) TRAP #14                   */
   isr_default,                               /*  47 (0x0BC) TRAP #15                   */
   isr_default,                               /*  48 (0x0C0) Reserved                   */
   isr_default,                               /*  49 (0x0C4) Reserved                   */
   isr_default,                               /*  50 (0x0C8) Reserved                   */
   isr_default,                               /*  51 (0x0CC) Reserved                   */
   isr_default,                               /*  52 (0x0D0) Reserved                   */
   isr_default,                               /*  53 (0x0D4) Reserved                   */
   isr_default,                               /*  54 (0x0D8) Reserved                   */
   isr_default,                               /*  55 (0x0DC) Reserved                   */
   isr_default,                               /*  56 (0x0E0) Reserved                   */
   isr_default,                               /*  57 (0x0E4) Reserved                   */
   isr_default,                               /*  58 (0x0E8) Reserved                   */
   isr_default,                               /*  59 (0x0EC) Reserved                   */
   isr_default,                               /*  60 (0x0F0) Reserved                   */
   isr_default,                               /*  61 (0x0F4) Reserved                   */
   isr_default,                               /*  62 (0x0F8) Reserved                   */
   isr_default,                               /*  63 (0x0FC) Reserved                   */
   isr_default,                               /*  64 (0x100) Device-specific interrupts */
   isr_default,                               /*  65 (0x104) Device-specific interrupts */
   isr_default,                               /*  66 (0x108) Device-specific interrupts */
   isr_default,                               /*  67 (0x10C) Device-specific interrupts */
   isr_default,                               /*  68 (0x110) Device-specific interrupts */
   isr_default,                               /*  69 (0x114) Device-specific interrupts */
   isr_default,                               /*  70 (0x118) Device-specific interrupts */
   isr_default,                               /*  71 (0x11C) Device-specific interrupts */
   isr_default,                               /*  72 (0x120) Device-specific interrupts */
   isr_default,                               /*  73 (0x124) Device-specific interrupts */
   isr_default,                               /*  74 (0x128) Device-specific interrupts */
   isr_default,                               /*  75 (0x12C) Device-specific interrupts */
   isr_default,                               /*  76 (0x130) Device-specific interrupts */
   isr_default,                               /*  77 (0x134) Device-specific interrupts */
   isr_default,                               /*  78 (0x138) Device-specific interrupts */
   isr_default,                               /*  79 (0x13C) Device-specific interrupts */
   isr_default,                               /*  80 (0x140) Device-specific interrupts */
   isr_default,                               /*  81 (0x144) Device-specific interrupts */
   isr_default,                               /*  82 (0x148) Device-specific interrupts */
   isr_default,                               /*  83 (0x14C) Device-specific interrupts */
   isr_default,                               /*  84 (0x150) Device-specific interrupts */
   isr_default,                               /*  85 (0x154) Device-specific interrupts */
   isr_default,                               /*  86 (0x158) Device-specific interrupts */
   isr_default,                               /*  87 (0x15C) Device-specific interrupts */
   isr_default,                               /*  88 (0x160) Device-specific interrupts */
   isr_default,                               /*  89 (0x164) Device-specific interrupts */
   isr_default,                               /*  90 (0x168) Device-specific interrupts */
   isr_default,                               /*  91 (0x16C) Device-specific interrupts */
   isr_default,                               /*  92 (0x170) Device-specific interrupts */
   isr_default,                               /*  93 (0x174) Device-specific interrupts */
   isr_default,                               /*  94 (0x178) Device-specific interrupts */
   isr_default,                               /*  95 (0x17C) Device-specific interrupts */
   isr_default,                               /*  96 (0x180) Level 1 software interrupt */
   isr_default,                               /*  97 (0x184) Level 2 software interrupt */
   isr_default,                               /*  98 (0x188) Level 3 software interrupt */
   isr_default,                               /*  99 (0x18C) Level 4 software interrupt */
   isr_default,                               /* 100 (0x190) Level 5 software interrupt */
   isr_default,                               /* 101 (0x194) Level 6 software interrupt */
   isr_default,                               /* 102 (0x198) Level 7 software interrupt */
   isr_default,                               /* 103 (0x19C) Reserved                   */
   isr_default,                               /* 104 (0x1A0) Reserved                   */
   isr_default,                               /* 105 (0x1A4) Reserved                   */
   isr_default,                               /* 106 (0x1A8) Reserved                   */
   isr_default,                               /* 107 (0x___) Reserved                   */
   isr_default,                               /* 108 (0x___) Reserved                   */
   isr_default,                               /* 109 (0x___) Reserved                   */
   isr_default,                               /* 110 (0x___) Reserved                   */
   isr_default,                               /* 111 (0x___) Reserved                   */
   isr_default,                               /* 112 (0x___) Reserved                   */
   isr_default,                               /* 113 (0x___) Reserved                   */
   isr_default,                               /* 114 (0x___) Reserved                   */
   isr_default,                               /* 115 (0x___) Reserved                   */
   isr_default,                               /* 116 (0x___) Reserved                   */
   isr_default,                               /* 117 (0x___) Reserved                   */
   isr_default,                               /* 118 (0x___) Reserved                   */
   isr_default,                               /* 119 (0x___) Reserved                   */
   isr_default,                               /* 120 (0x___) Reserved                   */
   isr_default,                               /* 121 (0x___) Reserved                   */
   isr_default,                               /* 122 (0x___) Reserved                   */
   isr_default,                               /* 123 (0x___) Reserved                   */
   isr_default,                               /* 124 (0x___) Reserved                   */
   isr_default,                               /* 125 (0x___) Reserved                   */
   isr_default,                               /* 126 (0x___) Reserved                   */
   isr_default,                               /* 127 (0x___) Reserved                   */
   isr_default,                               /* 128 (0x___) Reserved                   */
   isr_default,                               /* 129 (0x___) Reserved                   */
   isr_default,                               /* 130 (0x___) Reserved                   */
   isr_default,                               /* 131 (0x___) Reserved                   */
   isr_default,                               /* 132 (0x___) Reserved                   */
   isr_default,                               /* 133 (0x___) Reserved                   */
   isr_default,                               /* 134 (0x___) Reserved                   */
   isr_default,                               /* 135 (0x___) Reserved                   */
   isr_default,                               /* 136 (0x___) Reserved                   */
   isr_default,                               /* 137 (0x___) Reserved                   */
   isr_default,                               /* 138 (0x___) Reserved                   */
   isr_default,                               /* 139 (0x___) Reserved                   */
   isr_default,                               /* 140 (0x___) Reserved                   */
   isr_default,                               /* 141 (0x___) Reserved                   */
   isr_default,                               /* 142 (0x___) Reserved                   */
   isr_default,                               /* 143 (0x___) Reserved                   */
   isr_default,                               /* 144 (0x___) Reserved                   */
   isr_default,                               /* 145 (0x___) Reserved                   */
   isr_default,                               /* 146 (0x___) Reserved                   */
   isr_default,                               /* 147 (0x___) Reserved                   */
   isr_default,                               /* 148 (0x___) Reserved                   */
   isr_default,                               /* 149 (0x___) Reserved                   */
   isr_default,                               /* 150 (0x___) Reserved                   */
   isr_default,                               /* 151 (0x___) Reserved                   */
   isr_default,                               /* 152 (0x___) Reserved                   */
   isr_default,                               /* 153 (0x___) Reserved                   */
   isr_default,                               /* 154 (0x___) Reserved                   */
   isr_default,                               /* 155 (0x___) Reserved                   */
   isr_default,                               /* 156 (0x___) Reserved                   */
   isr_default,                               /* 157 (0x___) Reserved                   */
   isr_default,                               /* 158 (0x___) Reserved                   */
   isr_default,                               /* 159 (0x___) Reserved                   */
   isr_default,                               /* 160 (0x___) Reserved                   */
   isr_default,                               /* 161 (0x___) Reserved                   */
   isr_default,                               /* 162 (0x___) Reserved                   */
   isr_default,                               /* 163 (0x___) Reserved                   */
   isr_default,                               /* 164 (0x___) Reserved                   */
   isr_default,                               /* 165 (0x___) Reserved                   */
   isr_default,                               /* 166 (0x___) Reserved                   */
   isr_default,                               /* 167 (0x___) Reserved                   */
   isr_default,                               /* 168 (0x___) Reserved                   */
   isr_default,                               /* 169 (0x___) Reserved                   */
   isr_default,                               /* 170 (0x___) Reserved                   */
   isr_default,                               /* 171 (0x___) Reserved                   */
   isr_default,                               /* 172 (0x___) Reserved                   */
   isr_default,                               /* 173 (0x___) Reserved                   */
   isr_default,                               /* 174 (0x___) Reserved                   */
   isr_default,                               /* 175 (0x___) Reserved                   */
   isr_default,                               /* 176 (0x___) Reserved                   */
   isr_default,                               /* 177 (0x___) Reserved                   */
   isr_default,                               /* 178 (0x___) Reserved                   */
   isr_default,                               /* 179 (0x___) Reserved                   */
   isr_default,                               /* 180 (0x___) Reserved                   */
   isr_default,                               /* 181 (0x___) Reserved                   */
   isr_default,                               /* 182 (0x___) Reserved                   */
   isr_default,                               /* 183 (0x___) Reserved                   */
   isr_default,                               /* 184 (0x___) Reserved                   */
   isr_default,                               /* 185 (0x___) Reserved                   */
   isr_default,                               /* 186 (0x___) Reserved                   */
   isr_default,                               /* 187 (0x___) Reserved                   */
   isr_default,                               /* 188 (0x___) Reserved                   */
   isr_default,                               /* 189 (0x___) Reserved                   */
   isr_default,                               /* 190 (0x___) Reserved                   */
   isr_default,                               /* 191 (0x___) Reserved                   */
   isr_default,                               /* 192 (0x___) Reserved                   */
   isr_default,                               /* 193 (0x___) Reserved                   */
   isr_default,                               /* 194 (0x___) Reserved                   */
   isr_default,                               /* 195 (0x___) Reserved                   */
   isr_default,                               /* 196 (0x___) Reserved                   */
   isr_default,                               /* 197 (0x___) Reserved                   */
   isr_default,                               /* 198 (0x___) Reserved                   */
   isr_default,                               /* 199 (0x___) Reserved                   */
   isr_default,                               /* 200 (0x___) Reserved                   */
   isr_default,                               /* 201 (0x___) Reserved                   */
   isr_default,                               /* 202 (0x___) Reserved                   */
   isr_default,                               /* 203 (0x___) Reserved                   */
   isr_default,                               /* 204 (0x___) Reserved                   */
   isr_default,                               /* 205 (0x___) Reserved                   */
   isr_default,                               /* 206 (0x___) Reserved                   */
   isr_default,                               /* 207 (0x___) Reserved                   */
   isr_default,                               /* 208 (0x___) Reserved                   */
   isr_default,                               /* 209 (0x___) Reserved                   */
   isr_default,                               /* 210 (0x___) Reserved                   */
   isr_default,                               /* 211 (0x___) Reserved                   */
   isr_default,                               /* 212 (0x___) Reserved                   */
   isr_default,                               /* 213 (0x___) Reserved                   */
   isr_default,                               /* 214 (0x___) Reserved                   */
   isr_default,                               /* 215 (0x___) Reserved                   */
   isr_default,                               /* 216 (0x___) Reserved                   */
   isr_default,                               /* 217 (0x___) Reserved                   */
   isr_default,                               /* 218 (0x___) Reserved                   */
   isr_default,                               /* 219 (0x___) Reserved                   */
   isr_default,                               /* 220 (0x___) Reserved                   */
   isr_default,                               /* 221 (0x___) Reserved                   */
   isr_default,                               /* 222 (0x___) Reserved                   */
   isr_default,                               /* 223 (0x___) Reserved                   */
   isr_default,                               /* 224 (0x___) Reserved                   */
   isr_default,                               /* 225 (0x___) Reserved                   */
   isr_default,                               /* 226 (0x___) Reserved                   */
   isr_default,                               /* 227 (0x___) Reserved                   */
   isr_default,                               /* 228 (0x___) Reserved                   */
   isr_default,                               /* 229 (0x___) Reserved                   */
   isr_default,                               /* 230 (0x___) Reserved                   */
   isr_default,                               /* 231 (0x___) Reserved                   */
   isr_default,                               /* 232 (0x___) Reserved                   */
   isr_default,                               /* 233 (0x___) Reserved                   */
   isr_default,                               /* 234 (0x___) Reserved                   */
   isr_default,                               /* 235 (0x___) Reserved                   */
   isr_default,                               /* 236 (0x___) Reserved                   */
   isr_default,                               /* 237 (0x___) Reserved                   */
   isr_default,                               /* 238 (0x___) Reserved                   */
   isr_default,                               /* 239 (0x___) Reserved                   */
   isr_default,                               /* 240 (0x___) Reserved                   */
   isr_default,                               /* 241 (0x___) Reserved                   */
   isr_default,                               /* 242 (0x___) Reserved                   */
   isr_default,                               /* 243 (0x___) Reserved                   */
   isr_default,                               /* 244 (0x___) Reserved                   */
   isr_default,                               /* 245 (0x___) Reserved                   */
   isr_default,                               /* 246 (0x___) Reserved                   */
   isr_default,                               /* 247 (0x___) Reserved                   */
   isr_default,                               /* 248 (0x___) Reserved                   */
   isr_default,                               /* 249 (0x___) Reserved                   */
   isr_default,                               /* 250 (0x___) Reserved                   */
   isr_default,                               /* 251 (0x___) Reserved                   */
   isr_default,                               /* 252 (0x___) Reserved                   */
   isr_default,                               /* 253 (0x___) Reserved                   */
   isr_default,                               /* 254 (0x___) Reserved                   */
   isr_default,                               /* 255 (0x___) Reserved                   */ 
};
