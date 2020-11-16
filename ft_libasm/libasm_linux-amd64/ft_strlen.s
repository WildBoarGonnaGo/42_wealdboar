global ft_strlen

section .text
ft_strlen:
	push	rdi
	xor		rax, rax
.loop:
	cmp		byte [rdi], 0
	je		.return
	inc		rdi
	inc		rax
	jmp		.loop
.return:
	pop		rdi
	ret
