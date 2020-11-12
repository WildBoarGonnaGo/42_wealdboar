global ft_putchar

section .text
ft_putchar:	
	push	rsi
	mov		rsi, rdi	
	mov		rdi, 0x01
	mov		rdx, 1
	mov		rax, 1
	push	rsi
	mov		rsi, rsp
	syscall
	pop 	rsi
	pop		rsi
	ret
