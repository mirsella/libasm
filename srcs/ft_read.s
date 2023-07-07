section .text
extern __errno_location
global ft_read

ft_read:
mov	rax, 0 ; 0 is code for read
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
