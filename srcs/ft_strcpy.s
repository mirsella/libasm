global ft_strcpy
; rdi = destination string
; rsi = source string

ft_strcpy:
xor rcx, rcx

cmp rsi, 0
jz return

copy_loop:
mov al, [rsi]
mov [rdi+rcx], al
inc rcx
inc rsi
cmp byte [rsi], 0
jne copy_loop

return:
mov rax, rdi
mov	byte [rdi+rcx], 0
ret
