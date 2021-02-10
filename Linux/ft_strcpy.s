; Assembly ft_read
; For Linux Systems

; ft_strcpy prototype:
; char *ft_strcpy(char *src, char *dst)
; char *ft_strcpy(      rdi,       rsi)

	global  ft_strcpy     ; Da acceso desde fuera a la funcion

section.text:
  
ft_strcpy:
    push rdx                ; Voy a usar el rdx, guardo en la pila el valor actual
    push rcx                ; Voy a usas el rcx como contador, guardo en la pila el valor actaul
    mov rcx, 0x0;           ; inicio a cero el contador
    mov rdx, 0x0;           ; inicio a cero el registro donde voy a guardar el dato
    cmp rsi, byte 0x0       ; miro si rsi (2º parametro) es vacia;
    jz _is_null             ; si la comparacion es true salta a salida
    
    _start_loop:
      mov dl, byte [rsi + rcx]  ; cargo en registro rdx -> dl(low)(8bits) el valor de [rsi+rcx]
      mov byte[rdi + rcx], dl   ;
      cmp [rsi + rcx], byte 0x0 ; miro si he llegado al final de la cadena 2 (rsi)
      jz _end_loop
      inc rcx;                  ; incrementa el contador
      jmp _start_loop           ; hago el bucle
    
    _end_loop:
    mov rax, rdi            ; copia rdi en el de salida (rax)
    pop rdx                 ; recupero el valor rdx de la pila
    pop rcx                 ; recupero el valor rcx de la pila
    ret                     ; retorno rax

_is_null:
    mov rax, rsi            ;
    pop rdx                 ; recupero el valor rdx de la pila
    pop rcx                 ; recupero el valor rcx de la pila
    ret                     ; retorno rax
