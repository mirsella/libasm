global ft_strdup
extern ft_strlen
extern ft_strcpy
extern __errno_location
extern malloc

ft_strdup:
call ft_strlen
inc	rax ; for \0
push rdi ; backup rdi (char *s)
mov	rdi, rax
call malloc wrt ..plt
cmp	rax, 0
jz error
mov	rdi, rax
pop	rsi ; restore char *s to rsi
call ft_strcpy
ret

error:
neg	rax
mov	rdi, rax
call __errno_location wrt ..plt
mov	[rax], rdi
mov	rax, -1
ret
