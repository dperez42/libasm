; Assembly ft_read
; For MacOX Systems

; ft_strcpy prototype:
; char *ft_strcpy(char *src, char *dst)
; char *ft_strcpy(      rdi,       rsi)

section.text:
	global  _ft_strcpy     		; Da acceso desde fuera a la funcion

_ft_strcpy:
    					mov		rax, -1
_start_loop:
							inc rax
    					mov cl, byte[rsi+rax]        
    				  mov	byte byte[rdi+rax], cl
							cmp cl, 0
							je _end_loop
							jmp _start_loop
_end_loop:
							movsx	rax, cl
							movsx rdx, dl
							mov		rax, rdi
							ret
