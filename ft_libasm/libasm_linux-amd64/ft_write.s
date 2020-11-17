global ft_write
extern __errno_location

section .text
ft_write:
	mov		rax, 0x01
	syscall
	cmp		rax, 0
	jl		err_hndl
	ret
err_hndl:
	neg		rax
	push	rax
	call	__errno_location
	pop		r8
	mov		[rax], r8
	mov 	rax, -1
	ret
