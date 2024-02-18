// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
//while true
//	if R[KBD]=0
//		pixels = 0
//	else
//		pixels = -1
//
//	for i = SCREEN; i < 8192; i++
//		R[i]=pixels
//

(BEGIN) // while true
@KBD
D=M

@NEQ
D;JNE // if KBD != 0 goto NEQ

@pixels
M=0 // if KBD == 0 then pixels = 0

(PRINT)
@SCREEN
D=A
@i
M=D // i = SCREEN

@24576 // = SCREEN (16384) + 8192 () 
D=A
@n
M=D // n = 8192

(PRINTLOOP)
@n
D=M
@i
D=D-M // n - i
@BEGIN
D;JLE // if n - i <= 0 or n <= i goto BEGIN -> for i = SCREEN; i < 8192; i++
//TO DO
@pixels
D=M
@i
A=M
M=D // R[i] = pixels
//TO DO
@i
D=M+1
M=D // i++

@PRINTLOOP
0;JMP

(NEQ)
@pixels
M=-1 // if KBD != 0 then pixels = -1
@PRINT
0;JMP

@BEGIN
0;JMP