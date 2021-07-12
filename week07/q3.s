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

 first_element = a[0]

# if (length == 1)
#   return first_element;
    
end1:

# calculate &a[1]
# length - 1
# max_so_far = max(&a[1], length - 1);

# if (first_element > max_so_far)

end2:

# return max_so_far

max_return:
    # epilogue



# some test code which calls max
main:
    addi $sp, $sp, -4  # create stack frame
    sw   $ra, 0($sp)   # save return address

# printf ("%d")

# printf("%c", '\n');

                       # clean up stack frame
    lw   $ra, 0($sp)   # restore $ra
    addi $sp, $sp, 4   # restore sp

    li  $v0, 0         # return 0
    jr  $ra


.data
array:
    .word 1 2 3 4 5 6 4 3 2 1
