global ft_strdup
extern malloc
extern ft_strlen

section .text
ft_strdup:
	xor		rax, rax
	push	rdi
	push	rax
	call	ft_strlen
	mov		rsi, rax
	pop		rax
	mov		rdi, rsi
	call	malloc
	pop		rdi
	xor		rsi, rsi
.loop:
	mov		cl, byte [rdi + rsi]
	mov		byte [rax + rsi], cl
	cmp		byte [rdi + rsi], 0
	je		.fin
	inc		rsi
	jmp		.loop
.fin:
	ret
