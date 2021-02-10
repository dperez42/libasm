; Assembly ft_read
; For MacOX Systems

; ft_strcmp prototype:
; int ft_strcmp(char *str1, char *srt2);
; int ft_strcmp(      rdi,       rsi);

section.text:
	  global _ft_strcmp             ;declaro la funcion global

_ft_strcmp:
						mov rax, 0
_start_loop:
    				mov al, byte[rdi]
    				mov bl, byte[rsi]
						cmp al, 0
						je _exit
						cmp bl, 0
						je _exit
						cmp al, bl
						jne _exit
						inc rdi
						inc rsi
						jmp _start_loop
_exit:
					movzx rax, al
					movzx	rbx, bl
					sub rax, rbx
					cmp rax, 0
					je _end0
					cmp rax, 0
					jl _end1
					jmp _end2

_end0:
				mov rax, 0
				ret
_end1:
				mov rax, -1
				ret
_end2:
				mov rax, 1
				ret
