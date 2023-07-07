section .text
extern __errno_location
global ft_write

ft_write:
mov	rax, 1 ; 1 is code for write
syscall
cmp	rax, 0 ; rax contain write return value
jl error
ret

error:
mov	rdi, rax
neg	rdi ; the errno code is negative for a error
call __errno_location wrt ..plt; rax now point to errno
mov	[rax], rdi
mov	rax, -1
ret
