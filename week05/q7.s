# read 10 numbers into an array
# print 10 numbers from an array

# i in register $t0
# numbers in register $t1

main:

    la $a0 scan         # load print into $a0
    li $v0 4            # syscall 4: print_string
    syscall             # printf("Scan:\n");

    # i = 0
    li  $t0 0 # i = 0

scan_loop:
    # if (i >= 10) goto scan_end
    bge $t0 10 scan_end # while (i < 10)

    li $v0 5            # syscall 1: print_int
    syscall             # scanned in value is $v0
    
    # 1st loop: numbers + (0 * 4)
    # 2nd loop: numbers + (1 * 4)
    # 3rd loop: numbers + (2 * 4)
    # ...

    mul $t2 $t0 4       # $t2 = i * 4
    la $t1 numbers      # $t2 = numbers
    add $t3 $t2 $t1     # $t3 = numbers + (i * 4)
    sw $v0 ($t3)        # scanf("%d" &numbers[1]);

    # $t0 = $t0 + 1
    addi $t0 $t0 1      # i++;
    j scan_loop

scan_end:

    la $a0 print        # load print into $a0
    li $v0 4            # syscall 4: print_string
    syscall             # printf("Print:\n");

    # i = 0
    li  $t0 0 # i = 0

print_loop:
    # if (i >= 10) goto print_end
    bge $t0 10 print_end    # while (i < 10)

    mul $t2 $t0 4       # $t2 = i * 4
    la $t1 numbers      # $t2 = numbers
    add $t3 $t2 $t1     # $t3 = numbers + (i * 4)

    lw $a0 ($t3)        # print $a0 in syscall
    li $v0 1            # syscall 1: print_int
    syscall             # printf("%d" numbers[i]);

    # '\n' == 10
	li $a0 10           # print '\n; in syscall
	li $v0 11           # syscall 1: print_character
	syscall             # printf("\n");

    # $t0 = $t0 + 1
    addi $t0 $t0 1      # i++;
    j print_loop

print_end:

    jr   $ra            # return

    .data
numbers:
    .word 0 0 0 0 0 0 0 0 0 0   # int numbers[10] = {0};

scan:
    .asciiz "Scan:\n"

print:
    .asciiz "Print:\n"
