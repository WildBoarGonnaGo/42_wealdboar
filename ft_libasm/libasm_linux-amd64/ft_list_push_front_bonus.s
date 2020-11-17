global ft_list_push_front
extern malloc

ft_list_push_front:
section .text
	xor		rax, rax
	cmp		rdi, 0
	jz		.return
	push	rax
	push	rdi
	push	rsi
	mov		rdi, 16
	call	malloc
	pop		rsi
	pop		rdi
	mov		rcx, rax
	pop		rax
	mov		[rcx], rsi
	push	rcx
	add		rcx, 8
	mov		rdx, [rdi]
	mov		[rcx], rdx
	pop		rcx
	mov		[rdi], rcx
.return:
	ret
