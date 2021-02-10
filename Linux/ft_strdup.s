; Assembly ft_read
; For Linux Systems

; ft_read prototype:
; char *ft_strdup(char *str);
; char *ft_strdup(      rdi);

  global ft_strdup
  extern ft_strlen
  extern ft_strcpy
  extern malloc

section.text:

ft_strdup:
  	cmp rdi, 0x0      ;si cadena NULL error
  	jz _error
  	call ft_strlen   ;guardo en rax la longitud de la cadena
  	inc rax          ;añado 1 para final de cadena
  	push rdi         ;guardo el valor de rdi en la pila
 	mov rdi, rax     ;coloco el valor de rax de rdi
  	call malloc      ;hago un malloc(rdi)
  	cmp rax, 0x0     ;si la longitud de cadena+1 = 0 GO ERROR
	jz _error	   ; si rax = 0, no se ha podido malloc
	pop rdi		
	push rsi	; reservo el valor de rsi
	mov rsi, rdi	; cargo en rsi el string 
	mov rdi, rax	; carfo en rdi el nuevo string
	call ft_strcpy	; llamo a srtcpy(rdi,rsi)
	pop rsi		; recupero el valor de rsi
	ret		; retorno rax

_error:
  mov rax, 0x0
  ret
