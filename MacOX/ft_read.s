; Assembly ft_read
; For MAcOX Systems

; ft_read prototype:
; ssize_t	ft_read(int fd, void *buf, size_t nbyte);
; ssize_t	ft_read(rdi, rsi, rdx);

section.text:
	extern		___error
	global		_ft_read

_ft_read:
		mov	rax, 0x2000003		; Set rax with 0x2000003 == "READ" system call in MacOX
		syscall								; system call
		jc error							; if some error jump error
		ret										; return result of syscall (rax) number of read bytes

error:
		push rdi							; reserve rdi in stack
		mov  rdi, rax					; set rdi with rax (error number)
		call ___error					; call funcion error(rdi)
		mov [rax], rdi  			; set the value of errno
		pop rdi								; recover rdi from stack
		mov rax, -1						; set rax to -1 (error)
		ret										; return rax (-1)
