; Assembly ft_read
; For Linux Systems

; ft_strlen prototype:
; size_t ft_strlen(char *str)
; size_t ft_strlen(rdi)

    	global  ft_strlen

section.text:

ft_strlen:
    		mov rax, 0x0                ; rax es el registro de salida, lo usamos como contador y lo ponemos a 0
  		_start_loop:                ; etiqueta de inicio de loop
  		cmp byte [rdi + rax], 0x0   ; compara el byte[rdi + rax] con "\0"
  		jz _end_loop                ; si la comparacion es true ve a la etiqueta _end_loop
  		inc rax	                    ; incrementa rx(contador)
  		jmp _start_loop             ; salta a la etiqueta _start_loop
  	_end_loop:
  	ret                           	    ; retorno (return)
