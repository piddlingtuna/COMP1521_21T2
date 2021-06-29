# read 10 numbers into an array
# i in register $t0
# address of numbers in register $t1
main:

# i = 0
li  $t0, 0
la $t1, numbers
# while (i < 10) {
scan_loop:
    bge $t0, 2 scan_end

    li $v0, 5
    syscall
    # scanned in value is $v0
    
    mul $t2, $t0, 4 # $t2 = i * 4
    # la $t1, numbers # be careful
    add $t3, $t1, $t2
    # $t3 = numbers + $t2
    # $t3 = numbers + i * 4
    # $t3 has the value of &numbers[i]

    sw $v0, ($t3)
    # 1st loop: numbers + (0 * 4)
    # 2nd loop: numbers + (1 * 4)
    # 3rd loop: numbers + (2 * 4)
    # ...

    # i++
    addi $t0, $t0, 1 # $t0 = $t0 + 1
    j scan_loop
scan_end:

li  $t0 0
print_loop:
    bge $t0, 2 print_end

    mul $t2, $t0, 4 # $t2 = i * 4
    # la $t1, numbers # be careful
    add $t3, $t1, $t2
    lw $a0, ($t3)
    li $v0, 1
    syscall

# printf("\n");
	li $v0, 11
	li $a0, 10, # '\n' == 10
	syscall

    addi $t0, $t0, 1 # $t0 = $t0 + 1
    j print_loop
print_end:

    jr   $ra            # return

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};
