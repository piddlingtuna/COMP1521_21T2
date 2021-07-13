# Recursive maximum of array function

# Register usage:
#   - `a' is in $a0
#   - `length' is in $a1
#   - `first_element' is in $s0
#   - `max_so_far' is in $t0

# s0 & s1 used for a and first_element because they need
# to keep their value across recursive call

max:
    # prologue
    addi $sp, $sp, -8  # create stack frame
    sw   $ra, 4($sp)   # save return address
    sw   $s0, 0($sp)   # save $s0

# first_element = a[0]
    lw $s0 ($a0)
    

# if (length == 1)
    bne $a1 1, end1
#   return first_element;
    move $v0, $s0
    # jr $ra
    j max_return
    
end1:

    addi $a0 $a0 4
    addi $a1, $a1, -1
    jal max
    move $t0 $v0 # $v0 return value
# calculate &a[1]
# length - 1
# max_so_far = max(&a[1], length - 1);

# if (first_element > max_so_far)
    ble $s0, $t0, end2 # less than or equal to <=
    move $v0, $s0 # first_element is the biggest
    j max_return

end2:

# return max_so_far
    move $v0 $t0 # max_so_far is the biggest

max_return:
    # epilogue
                       # clean up stack frame
    lw   $s0, 0($sp)   # restore $s0
    lw   $ra, 4($sp)   # restore $ra
    
    addi $sp, $sp, 8   # restore sp
    


# some test code which calls max
main:
    addi $sp, $sp, -4  # create stack frame
    sw   $ra, 0($sp)   # save return address
    
    la   $a0, array
    li   $a1, 10
    jal   max    #


    move  $a0, $v0     # printf ("%d")
    li    $v0, 1
    syscall

    li   $a0, 10     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $ra, 0($sp)   # restore $ra
    addi $sp, $sp, 4   # restore sp

    li  $v0, 0         # return 0
    jr  $ra


.data
array:
    .word 1 2 3 4 5 6 4 3 2 1



#------------------------- <-- $sp - stack pointer 0x7ffffffff



    #jal max # max is a function <- $PC Program counter
    
    # jal stans for jump and link
    # saves PC+4 into $ra - link


#$s4





#--------------------------- 0x000000000000
