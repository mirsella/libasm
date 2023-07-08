global ft_list_size

ft_list_size:
xor rdx, rdx

iterate:
cmp rdi, 0
je return
mov rdi, [rdi+8] ; on 64bit system void* is of size 8 bytes. in t_list the t_list* pointer is second
inc rdx
jmp iterate

return:
mov rax, rdx
ret
