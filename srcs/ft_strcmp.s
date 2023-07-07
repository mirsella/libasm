global	ft_strcmp
; rdi = s1
; rsi = s2

ft_strcmp:
xor		rcx, rcx
xor		rax, rax

comp:
cmp		BYTE[rdi + rcx], 0
je		return
cmp		BYTE[rsi + rcx], 0
je		return
mov		al, BYTE[rsi + rcx]
cmp		BYTE[rdi + rcx], al
jne		return
inc		rcx
jmp		comp

return:
; movzx is used to mov a smaller value to a larger register
movzx		rax, BYTE[rdi + rcx]
movzx		rdx, BYTE[rsi + rcx]
sub		rax, rdx
ret
