# Print the square of a number
    .text
main:
# x,y in $t0, $t1

# printf("Enter a number: ");
    la $a0, prompt
    li $v0, 4
    syscall

# scanf("%d", x);
    li $v0, 5
    syscall
    move $t0, $v0

# y = x * x
    mul $t1, $t0, $t0

# printf("%d", y);
    move $a0, $t1
    li $v0, 1
    syscall

# printf("%c", '\n'); '\n' == 10
    li $a0, 10 # load immediate
    li $v0, 11
    syscall

# return 0; - not quite the same
    jr $ra

    .data
prompt:
    .asciiz "Enter a number: "
