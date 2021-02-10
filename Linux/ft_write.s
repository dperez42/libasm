; Assembly ft_write
; For Linux Systems

; ft_write prototype:
; ssize_t	ft_write(int fildes, void *buf, size_t nbyte);
; ssize_t 	ft_write(rdi, rsi, rdx);


			extern  	__errno_location
			global		ft_write
section .text
ft_write:	
		
			mov rax, 1  ; sys_write (0x01)
    			syscall     ; call write
    			cmp rax, 0
    			jl error2
    			ret
			

error2:		neg rax    ; get absolute value of syscall return
	   	mov rdi, rax
		;mov rsi, 1
		;mov rdx, 1
	    	call __errno_location
	    	mov [rax], rdi  ; set the value of errno
	    	mov rax, -0x01
	    	ret
