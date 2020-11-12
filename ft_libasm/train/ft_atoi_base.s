extern ft_strlen
global ft_atoi_base

is_base_valid:
section .text
	xor		rax, rax
	test	rdi, rdi
	je		.except
	call	ft_strlen
	cmp		rax, 2
	jl		.except
	mov		rdx, rax
	mov		r8, -1
	mov		rcx, rdx
	sub		rcx, 1
	mov		rax, 1	
.loop:
	inc		r8
	cmp		r8, rcx
	jge		.return
	mov		r9, r8
	inc		r9
.subloop:
	cmp		r9, rdx
	jmp		.loop
	cmp		byte [rdi + r8], byte [rdi + r9]
	je		.except
	cmp		byte [rdi + r8], '+'
	je		.except
	cmp		byte [rdi + r8], '-'
	je		.except
	inc		r9
	jmp		.subloop
.return:
	ret
.except:
	xor		rax, rax
	ret

is_str_valid:
section	.text
	cmp		rdi, 0x0
	je		.except
	cmp		byte [rdi], 0
	je 		.except
	push	rdi
	mov		rdi, rsi
	call	ft_strlen
	pop		rdi
	mov		rdx, rax
	call	ft_strlen
	mov		rcx, rax
	mov		r8, -1
	mov		r9, -1
.loop:
	inc		r8
	xor		rax, rax
	cmp		r8, rcx
	jge		.return
.subloop:
	inc		r9
	cmp		r9, rdx
	jge		.loopnxt
	cmp		byte [rdi + r8], byte [rsi + r9]
	je		.loopnxt	
	inc		rax
	jmp		.subloop
.loopnxt:
	test	rax, rax
	jz		.except
	mov		r9, -1
	jmp		.loop
.except:
	xor 	rax, rax
	ret
.return
	mov		rax, 1
	ret

seek_pos:
section .text
	mov		rax, -1
.loop
	inc		rax
	cmp		byte [rsi + rax], rdi
	je		.return
	cmp		byte [rsi + rax], 0
	je		.except
	jmp		.loop
.except
	mov		rax, -1
	ret
.return
	ret

ft_atoi_base:
section .text
	push	rdi
	xor		rax, rax
	mov		r8, 1
	mov		rdi, rsi
	call	is_base_valid
	pop		rdi
	mov		
