global ft_strlen

section .text
ft_strlen:
	xor	rax, rax
cloop:
	cmp	byte [rdi], 0
	je	end
	inc	rdi
	inc	rax
	jmp	cloop
end:
	ret
