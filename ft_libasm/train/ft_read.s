global ft_read
extern __errno_location

section .text
ft_read:
	mov		rax, 0x00
	syscall
	cmp		rax, 0
	jl		err_hndl
	ret
err_hndl:
	call	__errno_location
	mov 	rax, -1
	ret
