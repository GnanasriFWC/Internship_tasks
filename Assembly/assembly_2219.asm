.include "/sdcard/assignment/setup/m328Pdef/m328Pdef.inc"

.equ AA = 0
.equ AB = 1
.equ AC = 1
.equ AD = 0
.equ C = 1
.equ D = 1
.equ LR = 0

_start:
	ldi r16, 0b00000100
	out DDRB, r16

main_loop:
	ldi r18, C
	ldi r19, D
	com r18
	com r19
	and r19,r18
	ldi r20, AA
	and r19, r20
	ldi r21, LR
	mov r21,r19

	ldi r18, C
	ldi r19, D
	com r18
	and r19,r18
	ldi r20, AB
	and r19, r20
	or r21,r19

	ldi r18, C
	ldi r19, D
	com r19
	and r19, r18
	ldi r20,AC
	and r19, r20
	or r21,r19

	ldi r18, C
	ldi r19, D
	and r19,r18
	ldi r20, AD
	and r19, r20
	or r21, r19

	ldi r30,C
	ldi r31,D
	eor r30,r31

	cp r21,r31
	breq led


led:
	ldi r25,0
	ldi r26,1
	cp r21,r26

	breq led_on

	cp r21,r25
	breq led_off

led_on:
	out PORTB,r16
	rjmp end_loop

led_off:
	ldi r17,0b00000000
	out PORTB,r17
	rjmp end_loop
end_loop:
	rjmp main_loop
