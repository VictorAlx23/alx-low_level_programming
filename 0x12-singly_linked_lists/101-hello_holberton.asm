global main
extern printf

main:
    ; call printf to print the message
    mov rdi, message ; set first argument to message
    xor eax, eax     ; clear eax to indicate success
    call printf      ; call printf function
    ret             m
format: db 'Hello, Holberton\n',0
