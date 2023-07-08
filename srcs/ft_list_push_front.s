global ft_list_push_front
extern malloc
extern __errno_location

; rdi t_list**
; rsi void*
; rsp is the stack pointer

ft_list_push_front:
push rdi
push rsi

mov rdi, 16 ; sizeof(t_list) is 16, 2 pointer
call malloc wrt ..plt
pop rsi
pop rdi
cmp rax, 0
jz error

mov QWORD [rax], rsi ; quad-word (8 bytes) to move the 8 bytes void* to the new t_list
mov rcx, QWORD [rdi]
mov QWORD [rax + 8], rcx ; set new t_list->next to rdi
mov QWORD [rdi], rax ; set the start pointer to the new t_list

return:
ret

error:
neg	rax
mov	rdi, rax
call __errno_location wrt ..plt
mov	[rax], rdi
mov	rax, -1
ret
