global ft_strcpy
; rdi = destination string
; rsi = source string

ft_strcpy:
xor rcx, rcx

cmp rsi, 0 ; in case *s is NULL
jz return

copy_loop:
cmp byte [rsi], 0 ; check for \0
je return
mov al, [rsi]
mov [rdi+rcx], al
inc rcx
inc rsi
cmp byte [rsi], 0
jmp copy_loop

return:
mov rax, rdi
mov	byte [rdi+rcx], 0
ret
