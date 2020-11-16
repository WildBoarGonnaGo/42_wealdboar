global	ft_list_size

ft_list_size:
section .text
	xor		rax, rax
	push	rdi
	cmp		rdi, 0
	jz		.return
.loop:
	inc		rax
	add		rdi, 8
	cmp		qword [rdi], 0
	jz		.return
	mov		rdi, [rdi]
	jmp		.loop
.return:
	pop		rdi
	ret
