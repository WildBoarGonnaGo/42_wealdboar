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
	call	__errno_location
	mov 	rax, -1
	ret
