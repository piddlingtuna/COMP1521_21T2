    .text

# x in register $t1

main:
# x = 24
    li $t0, 24

loop:
# if (i > 42) goto end0;
    bgt $t0, 42, end;

# printf("%d", x);
    move $a0, $t0
    li $v0, 1
    syscall

# printf("%c", '\n');
    li $a0, 10 # load immediate
    li $v0, 11
    syscall
    
# x += 3
    addi $t0, $t0, 3 # $t0 = $t0 + 3
    
    j loop

end:
# return 0; - not quite the same
jr $ra

    .data
