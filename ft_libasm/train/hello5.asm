%include "stud_io.inc"
global _start

section .text
_start:	xor		eax, eax
again:	PRINT	"Hello"
		PUTCHAR	10
		inc 	eax
		cmp		eax, 5
		jl		again
		FINISH
