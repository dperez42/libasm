; Assembly ft_write
; For MacOX Systems

; ft_write prototype:
; ssize_t	ft_write(int fildes, void *buf, size_t nbyte);
; ssize_t 	ft_write(rdi, rsi, rdx);

section .text
			extern  	___error
			global		_ft_write

_ft_write:

			mov rax, 0X2000004  ; Set rax with 0x2000004 == "WRITE" system call in MacOX
    	syscall     				; call write
    	jc error
    	ret

error:
			push rdi						; reserve rdi in stack
			mov  rdi, rax				; set rdi with rax (error number)
			call ___error				; call funcion error(rdi)
			mov [rax], rdi  		; set the value of errno
			pop rdi							; recover rdi from stack
			mov rax, -1					; set rax to -1 (error)
			ret									; return rax (-1)
