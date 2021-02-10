; Assembly ft_read
; For MacOX Systems

; ft_read prototype:
; char *ft_strdup(char *str);
; char *ft_strdup(      rdi);

section.text:
      global _ft_strdup
      extern _ft_strlen
      extern _ft_strcpy
      extern _malloc

_ft_strdup:
  	       cmp rdi, 0x0      ; compare str with NULL
  	       jz _error         ; if str == NULL jump _error
  	       call _ft_strlen   ; call ft_strlen(rdi) result in rax
  	       inc rax           ; rax + 1 for end of string
           push rdi          ; reserve rdi in stack
           mov rdi, rax      ; set rdi with len of string(rax)
           call _malloc      ; malloc(rdi)
           cmp rax, 0x0      ; si la longitud de cadena+1 = 0 GO ERROR
	         jz _error	       ; si rax = 0, no se ha podido malloc
	         pop rdi           ; recover value of rdi from stack
	         push rsi	         ; reserve value of rsi in stack
	         mov rsi, rdi	     ; set rsi, source string
	         mov rdi, rax	     ; set rdi, destination string
	         call _ft_strcpy	 ; call to strcpy(rdi,rsi)
	         pop rsi		       ; recover value of rsi from stack
	         ret		           ; return rax

_error:
          mov rax, 0x0      ; set rax with zero
          ret               ; retun rax (0)
