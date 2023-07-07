global ft_strlen

ft_strlen:
xor	rcx, rcx ; rcx is a register we can use to count

loop:
cmp	BYTE [rdi+rcx], 0
je return
inc	rcx
jmp	loop

return:
mov	rax, rcx
ret
