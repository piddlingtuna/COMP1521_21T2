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
    addi $sp $sp -8         # create stack frame
    sw   $ra 4($sp)         # save return address
    sw   $s0 0($sp)         # save $s0

    lw $s0 ($a0)            # first_element = a[0]
    

    bne $a1 1 max_base      # if (length == 1)
    move $v0 $s0            # return first_element;
    j max_return
    
max_recur:

    addi $a0 $a0 4          # &a[1]
    addi $a1 $a1 -1         # length - 1
    jal max                 # max(&a[1] length - 1);
    move $t0 $v0            # $v0 has return value

    ble $s0 $t0 max_recur   # if (first_element > max_so_far)
    move $v0 $s0            # first_element is the biggest
    j max_return

max_base:

    move $v0 $t0            # max_so_far is the biggest

max_return:
                            # epilogue
    lw   $s0 0($sp)         # restore $s0
    lw   $ra 4($sp)         # restore $ra
    addi $sp $sp 8          # restore sp


# Some test code which calls max
main:
                            # prologue
    addi $sp $sp -4         # save sp
    sw   $ra 0($sp)         # save $ra
    
    la   $a0 array
    li   $a1 10
    jal   max               # max(array, 10);

    move  $a0 $v0           # printf("%d");
    li    $v0 1
    syscall

    li   $a0 10             # printf("%c" '\n');
    li   $v0 11
    syscall

                            # epilogue
    lw   $ra 0($sp)         # restore $ra
    addi $sp $sp 4          # restore sp

    li  $v0 0               # return 0;
    jr  $ra


.data
array:
    .word 1 2 3 4 5 6 4 3 2 1

#jal max # max is a function <- $PC Program counter

# Program counter (PC) points to the next instruction
# jal means jump and link
# jal max means:
# - saves max into PC (jump)
# - saves old PC + 4 into $ra (link)

# -------- 0x7fffffff
old $ra
old $s0
# -------- <-- $sp - stack pointer 0x7ffffff7




# -------- 0x00000000
