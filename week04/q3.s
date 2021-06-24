# Print the square of a number

    .text
main:
# x,y in $t0, $t1

# printf("Enter a number: ");
    la $a0, prompt # load address
    li $v0, 4 # load immediate
    syscall

# scanf("%d", x);
    li $v0, 5
    syscall
    move $t0, $v0

# if (x <= 46340) goto square;
    ble $t0, 46340, square

# printf("square too big for 32 bits\n");
    la $a0, too_big # load address
    li $v0, 4 # load immediate
    syscall

# goto end;
    j end

square:
# y = x * x
    mul $t1, $t0, $t0

# printf("%d", y);
    move $a0, $t1
    li $v0, 1 # load immediate
    syscall

# printf("%c", '\n'); '\n' == 10
    li $a0, 10 # li $a0, '\n'
    li $v0, 11 # load immediate
    syscall

end:
# return 0; - not quite the same
    jr $ra

    .data
prompt:
    .asciiz "Enter a number: "
too_big:
    .asciiz "square too big for 32 bits\n"
