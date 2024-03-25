--- C:\Users\Student\Desktop\MicroProc_4.1\Volodymyr Dobrohorskyi\Lab1\Lab1\Debug/.././main.c
00000052  DEC R20		Decrement
00000053  BRPL PC-0x03		Branch if plus
00000054  MOVW R20,R26		Copy register pair
00000055  EOR R20,R22		Exclusive OR
00000056  OUT 0x18,R20		Out to I/O location
			if(counter == 7){
00000057  CPI R24,0x07		Compare with immediate
00000058  BRNE PC+0x1F		Branch if not equal
				way=1; counter=6;
00000059  LDI R24,0x06		Load immediate
0000005A  MOV R25,R30		Copy register
0000005B  RJMP PC+0x001C		Relative jump
			counter--;
0000005C  SUBI R24,0x01		Subtract immediate
			PORTB ^= _BV(counter);
0000005D  IN R22,0x18		In from I/O location
0000005E  MOVW R20,R18		Copy register pair
0000005F  MOV R0,R24		Copy register
00000060  RJMP PC+0x0003		Relative jump
00000061  LSL R20		Logical Shift Left
00000062  ROL R21		Rotate Left Through Carry
00000063  DEC R0		Decrement
00000064  BRPL PC-0x03		Branch if plus
00000065  EOR R20,R22		Exclusive OR
00000066  OUT 0x18,R20		Out to I/O location
			PORTB ^= _BV(counter+2);
00000067  IN R22,0x18		In from I/O location
00000068  LDI R20,0x02		Load immediate
00000069  ADD R20,R24		Add without carry
0000006A  MOVW R26,R18		Copy register pair
0000006B  RJMP PC+0x0003		Relative jump
0000006C  LSL R26		Logical Shift Left
0000006D  ROL R27		Rotate Left Through Carry
0000006E  DEC R20		Decrement
0000006F  BRPL PC-0x03		Branch if plus
00000070  MOVW R20,R26		Copy register pair
00000071  EOR R20,R22		Exclusive OR
00000072  OUT 0x18,R20		Out to I/O location
			if(counter == 0){
00000073  CPSE R24,R1		Compare, skip if equal
00000074  RJMP PC+0x0003		Relative jump
				way=0; counter = 1;
00000075  LDI R24,0x01		Load immediate
00000076  MOV R25,R23		Copy register
--- c:\program files (x86)\atmel\studio\7.0\toolchain\avr8\avr8-gnu-toolchain\avr\include\util/delay.h
	__builtin_avr_delay_cycles(__ticks_dc);
00000077  LDI R26,0xD3		Load immediate
00000078  LDI R27,0x30		Load immediate
00000079  SBIW R26,0x01		Subtract immediate from word
0000007A  BRNE PC-0x01		Branch if not equal
0000007B  RJMP PC+0x0001		Relative jump
0000007C  NOP 		No operation
0000007D  RJMP PC-0x003F		Relative jump
--- C:\Users\Student\Desktop\MicroProc_4.1\Volodymyr Dobrohorskyi\Lab1\Lab1\Debug/.././main.c
{
	DDRB=0xff;
0000007E  SER R24		Set Register
0000007F  OUT 0x17,R24		Out to I/O location
    pingpong();
00000080  CALL 0x00000036		Call subroutine
--- No source file -------------------------------------------------------------
00000082  CLI 		Global Interrupt Disable
00000083  RJMP PC-0x0000		Relative jump
00000084  NOP 		Undefined
00000085  NOP 		Undefined
00000086  NOP 		Undefined
00000087  NOP 		Undefined
00000088  NOP 		Undefined
00000089  NOP 		Undefined
0000008A  NOP 		Undefined
0000008B  NOP 		Undefined
0000008C  NOP 		Undefined
0000008D  NOP 		Undefined
0000008E  NOP 		Undefined
0000008F  NOP 		Undefined
00000090  NOP 		Undefined
00000091  NOP 		Undefined
00000092  NOP 		Undefined
00000093  NOP 		Undefined
00000094  NOP 		Undefined
00000095  NOP 		Undefined
00000096  NOP 		Undefined
00000097  NOP 		Undefined
00000098  NOP 		Undefined
00000099  NOP 		Undefined
0000009A  NOP 		Undefined
0000009B  NOP 		Undefined
0000009C  NOP 		Undefined
0000009D  NOP 		Undefined
0000009E  NOP 		Undefined
0000009F  NOP 		Undefined
000000A0  NOP 		Undefined
000000A1  NOP 		Undefined
000000A2  NOP 		Undefined
000000A3  NOP 		Undefined
000000A4  NOP 		Undefined
000000A5  NOP 		Undefined
000000A6  NOP 		Undefined
000000A7  NOP 		Undefined
000000A8  NOP 		Undefined
000000A9  NOP 		Undefined
000000AA  NOP 		Undefined
000000AB  NOP 		Undefined
000000AC  NOP 		Undefined
--- No source file -------------------------------------------------------------
000000AD  NOP 		Undefined
000000AE  NOP 		Undefined
000000AF  NOP 		Undefined
000000B0  NOP 		Undefined
000000B1  NOP 		Undefined
000000B2  NOP 		Undefined
000000B3  NOP 		Undefined
000000B4  NOP 		Undefined
000000B5  NOP 		Undefined
000000B6  NOP 		Undefined
000000B7  NOP 		Undefined
000000B8  NOP 		Undefined
000000B9  NOP 		Undefined
000000BA  NOP 		Undefined
000000BB  NOP 		Undefined
000000BC  NOP 		Undefined
000000BD  NOP 		Undefined
000000BE  NOP 		Undefined
000000BF  NOP 		Undefined
000000C0  NOP 		Undefined
000000C1  NOP 		Undefined
000000C2  NOP 		Undefined