;void	ft_list_sort(t_list **begin_list, int (*cmp)())
;{
;	int 	info[3];
;	t_list	*tool[3];
;	void 	*buf;

;	info[0] = ft_list_size(*begin_list);
;	info[1] = -1;
;	tool[0] = *begin_list;
;	while (++info[1] < info[0])
;	{
;		info[2] = -1;
;		tool[1] = tool[0];
;		tool[2] = tool[0]->next;
;		while (++info[2] < info[0] - 1)
;		{
;			if (cmp(tool[1]->data, tool[2]->data) > 0)
;			{
;				buf = tool[1]->data;
;				tool[1]->data = tool[2]->data;
;				tool[2]->data = buf;
;			}
;			tool[1] = tool[1]->next;
;			tool[2] = tool[1]->next;
;		}
;	}
;}
global ft_list_sort
extern ft_list_size

ft_list_sort:
section .bss
	info	resd 4
	tool	resq 6
section	.text
	push	rbx
	xor		r8, r8
	xor 	r9, r9
	mov		rcx, info
	mov		rdx, tool
	push	rdi
	mov		rdi, [rdi]
	call	ft_list_size
	mov		rdx, rdi
	pop		rdi
	mov		[rcx], rax
	mov		dword [rcx + 4], -1
	mov		[rcx + 12], rax
	sub		dword [rcx + 12], 1
.loop:
	add		dword [rcx + 4], 1
	mov		r8d, [rcx + 12]
	cmp		dword [rcx + 4], r8d
	jge		.return
	mov		dword [rcx + 8], -1
	mov		[rdx + 16], rdx
	mov		r8, [rdx + 8]
	mov		rbx, r8
	mov		[rdx + 32], rbx
	mov		
.subloop:
	add		dword [rcx + 8], 1
	mov		r8, [rcx]
	mov		r9d, dword [rcx + 8]
	cmp		r9d, r8d
	jge		.loop
.cmp:
	push	rdi
	push	rsi
	mov		r9, rsi
	push	r9
	mov		r8, [rdx + 16]
	mov		r9, [rdx + 32]
	mov		rdi, [r8]
	mov		rsi, [r9]
	pop		r9
	call 	r9
	pop		rdi
	pop		rsi
	cmp		rax, 0
	jl		.pass
	mov		r8, [rdx + 16]
	mov		r9, [rdx + 32]
	mov		[rdx + 16], r9
	mov		[rdx + 32], r8
.pass:
	mov		r8, rbx
	mov		r9, [r8 + 8]
	mov		[rdx + 16], r8
	mov		[rdx + 32], r9
	mov		rbx, r9
	jmp		.subloop
.return:
	pop		rbx
	xor		rax, rax
	ret		
