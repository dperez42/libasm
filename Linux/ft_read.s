; Assembly ft_read
; For Linux Systems

; ft_read prototype:
; ssize_t	ft_read(int fd, void *buf, size_t nbyte);
; ssize_t	ft_read(rdi, rsi, rdx);

	extern		__errno_location			
	global		ft_read

section .text:

ft_read:	
		mov	rax, 0
		syscall		; llamada la sistema con el valor rax (0 = read en linux)
		cmp	rax, 0  ; comparo el valor devuelto por syscall  (rax) con 0
		jl	err	; si <0 salta a err
		je	err1	; si =0 salta a err1 
		push rdx      	; guardo en la pila el rdx
		mov rdx, rax	; guardo en rdx el valor de rax (ret>0)
		mov rax, 0    	; valor de errno = 0 si rax>0.
		mov rdi, rax	; 
   	 	call __errno_location
    		mov [rax], rdi  ; set the value of errno
    		mov rax, rdx	;
		pop rdx		; repongo el valor anterior de rdx
		ret		; devuelo rax

err:				; ret < 0
		cmp rsi, 0x00		
		neg rax    		; valor absoluto de valor devuelto por syscall
		mov rdi, rax
   	 	call __errno_location
    		mov [rax], rdi  ; set the value of errno
    		mov rax, -1
    		ret

err1:				; ret = 0		
		cmp rsi, 0x00
		je erronull1		
		mov rax, 0;		
		mov rdi, rax
   	 	call __errno_location
    		mov [rax], rdi  ; set the value of errno	
		mov rax, 0
		ret

erronull1:	
		mov rax, 9;		
		mov rdi, rax
   	 	call __errno_location
    		mov [rax], rdi  ; set the value of errno	
		mov rax, 0
		ret
		