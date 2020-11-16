global ft_strcmp

section	.text
ft_strcmp:
	xor		rax, rax
	cmp 	rdi, 0
	jz		.exproc
	cmp		rsi, 0
	jz		.exproc
.cmp:	
	add		al, byte [rdi]
	sub		al, byte [rsi]
	cmp		al, 0
	jge		.posit
	sub		rax, 256
.posit:
	cmp		byte [rsi], 0
	je		.exproc
	cmp		byte [rdi], 0
	je		.exproc
	cmp		rax, 0
	jne		.exproc
	inc		rdi
	inc		rsi
	jmp		.cmp
.exproc:
	ret
