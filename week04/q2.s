# Print the square of a number
    .text
main: # labels
# x,y in $t0, $t1
# x = $t0
# y = $t1

# printf("Enter a number: "); # write
    la $a0, prompt # load address
    li $v0, 4 # load immediate
    syscall

# scanf("%d", x);
    li $v0, 5
    syscall
    move $t0, $v0
    
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

# return 0; - not quite the same
    jr $ra

    .data
prompt: # labels
    .asciiz "Enter a number: "
