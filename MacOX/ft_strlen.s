; Assembly ft_read
; For MacOX Systems

; ft_strlen prototype:
; size_t ft_strlen(char *str)
; size_t ft_strlen(rdi)

section.text:
    	global  _ft_strlen

_ft_strlen:
    		mov rax, 0x0                    ; init counter(rax) to cero
_start_loop:                            ; start loop
  		      cmp byte [rdi + rax], 0x0   ; compare byte[rdi + rax] with "\0"
            jz _end_loop                ; if comparation equals zero -> end of string -> jump _end_loop
            inc rax	                    ; increment counter
            jmp _start_loop             ; jump to _start_loop
_end_loop:
            ret                         ; return rax
