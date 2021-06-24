    .text
# x in register $t0

main:
# x = 24
    li $t0, 24 # $t0 = 24

loop:
# if (x >= 42) goto end;
    bge $t0, 42, end;
# printf("%d", x);
    move $a0, $t0
    li $v0, 1 # load immediate
    syscall

# printf("%c", '\n'); '\n' == 10
    li $a0, 10 # li $a0, '\n'
    li $v0, 11 # load immediate
    syscall
    
# x += 3
    addi $t0, $t0, 3 # x = x + 3

    
# goto loop
    j loop

end:
# return 0; - not quite the same
    jr $ra
