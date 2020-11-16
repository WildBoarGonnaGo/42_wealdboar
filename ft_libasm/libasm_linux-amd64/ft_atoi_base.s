extern ft_strlen
global ft_atoi_base

is_base_valid:
section .text
	push	rbx
	push 	rcx
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
	jge		.loop
	mov		bl, byte [rdi + r9]
	cmp		byte [rdi + r8], bl
	je		.except
	cmp		byte [rdi + r8], '+'
	je		.except
	cmp		byte [rdi + r8], '-'
	je		.except
	inc		r9
	jmp		.subloop
.return:
	pop		rcx
	pop		rbx
	ret
.except:
	pop		rcx
	pop		rbx
	xor		rax, rax
	ret

is_str_valid:
section	.text
	push	rbx
	push	rcx
	push	r9
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
	mov		bl, byte [rsi + r9]
	cmp		byte [rdi + r8], bl
	jne		.subloop	
	inc		rax
	jmp		.subloop
.loopnxt:
	test	rax, rax
	jz		.except
	mov		r9, -1
	jmp		.loop
.except:
	pop		r9
	pop		rcx
	pop		rbx
	xor 	rax, rax
	ret
.return:
	pop		r9
	pop		rcx
	pop		rbx
	mov		rax, 1
	ret

seek_pos:
section .text
	push	rcx
	mov		rax, -1
	mov		cl, byte [rdi]
.loop:
	inc		rax
	cmp		byte [rsi + rax], cl
	je		.return
	cmp		byte [rsi + rax], 0
	je		.except
	jmp		.loop
.except:
	pop		rcx
	mov		rax, -1
	ret
.return:
	pop		rcx
	ret

ft_atoi_base:
section .text
	mov		r8, 1
.space:
	cmp		byte [rdi], 32
	je		.frwrd
	cmp		byte [rdi], 14
	jge		.pls
	cmp		byte [rdi], 8
	jle		.pls
.frwrd:
	inc 	rdi
	jmp		.space
.pls:
	cmp		byte [rdi], '+'
	je		.step
	cmp		byte [rdi], '-'
	je		.neg
	jmp		.body
.neg:
	mov		r8, -1
.step:
	inc		rdi
.body:
	push	r8
	push	rdi	
	xor		rax, rax
	xor		rcx, rcx	
	mov		rdi, rsi
	call	is_base_valid
	or		rcx, rax
	mov		rdi, rsi
	call 	ft_strlen
	mov		r9, rax
	pop		rdi	
	call	is_str_valid
	shl		rax, 1
	or		rcx, rax
	cmp		rcx, 3
	jne		.except
	xor		rcx, rcx
	mov		rax, r9
	pop		r8
	push	rdi
.loop:
	cmp 	byte [rdi], 0
	jz		.return	
	push	rax
	mul		rcx
	mov		rcx, rax
	call	seek_pos
	add		rcx, rax
	pop		rax
	inc		rdi
	jmp		.loop
.except:
	pop		r8
	xor 	rax, rax
	ret
.return:
	pop		rdi
	mov		rax, rcx
	mul		r8
	ret
