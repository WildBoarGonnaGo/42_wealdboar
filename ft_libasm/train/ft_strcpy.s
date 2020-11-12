global ft_strcpy
extern ft_strlen

section .text
ft_strcpy:
	xor		rdx, rdx	
	push	rdi
	mov		rdi, rsi
	call	ft_strlen
	mov		rcx, rax
	pop		rdi
	mov		rax, rdi
cploop:
	mov		bl, byte [rsi + rdx]
	mov		byte [rax + rdx], bl
	cmp		rdx, rcx
	je		done
	inc		rdx
	jmp		cploop
done:
	ret
