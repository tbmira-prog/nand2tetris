// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

// Exemple:
// 3(x) * 7(y) = 7+7+7 = 21

@R0
D=M
@x
M=D // x = R0

@R1
D=M
@y
M=D // y = R1



D=M // D = y
@x
D=D-M // D = y - x
@SWAP
D;JLT // if y - x < 0 or y < x goto SWAP


(MULT)
@i
M=0 // i = 0
@R2
M=0 // ans = 0

(LOOP)
@i
D=M // D = i
@x
D=M-D // x - i
@END
D;JLE // if x - i <= 0 or x <= i goto END -> for i = 0; i < x; i++

@R2
D=M
@y
D=D+M
@R2
M=D // ans = ans + y
@i
M=M+1 // i++

@LOOP
0;JMP

(END)
@END
0;JMP // while true ;

(SWAP)
@x
D=M
@temp
M=D // temp = x
@y
D=M
@x
M = D // x = y
@temp
D=M
@y
M=D // y = temp
@MULT
0;JMP

// Loop test:

// LOOP
// x=3
// i=0
// x <= i -> 3 <= 0
// ans=7
// i=1
// LOOP
// x=3
// i=1
// x <= 1 -> 3 <= 1
// ans=14
// i=2
// LOOP
// x=3
// i=2
// x <= i -> 3 <= 2
// ans=21
// i=3
//LOOP
// x=3
// i=3
// x <= i -> 3 <= 3
// END

