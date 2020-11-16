global ft_strcpy
extern ft_strlen

section .text
ft_strcpy:
	xor		rdx, rdx
	xor		rax, rax
	cmp 	rdi, 0
	jz		.return
	cmp 	rsi, 0
	jz		.return
	push	rdi
	mov		rdi, rsi
	call	ft_strlen
	mov		rcx, rax
	pop		rdi
	mov		rax, rdi
.loop:
	mov		bl, byte [rsi + rdx]
	mov		byte [rax + rdx], bl
	cmp		rdx, rcx
	je		.return
	inc		rdx
	jmp		.loop
.return:
	ret
