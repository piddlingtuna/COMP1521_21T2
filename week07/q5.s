# sum 4 numbers using function calls
# note use of stack to save $ra in main
# and $ra $a0, $a1, $s0 in sum2
# for simplicity we are not using a frame pointer

main:
    addi $sp, $sp, -4   # move stack pointer down to make room
    sw   $ra, 0($sp)    # save $ra on $stack

                        # sum4(11, 13, 17, 19)
    jal sum4

    move $a0, $v0       # printf("%d", z);
    li   $v0, 1
    syscall

    li   $a0, 10        # printf("%c", '\n');
    li   $v0, 11
    syscall

    lw   $ra, 0($sp)    # recover $ra from $stack
    addi $sp, $sp, 4    # move stack pointer back up to what it was when main called

    li   $v0, 0         # return 0 from function main
    jr   $ra            # return from function main


# a,b,c,d are in $a0,$a1,$a2,$a3
# e is in $s0
# f is in $s1
#
# note sum2 is simple function which changes only $v0
# we could simplify sum4 by relying on this
# but in general we don't do this
# we assume only registers $s0..$s7 survive function calls

sum4:
    addi $sp, $sp, -12  # move stack pointer down to make room
    sw   $ra, 8($sp)   # save $ra on $stack
    sw   $s0, 4($sp)    # save $s0 on $stack
    sw   $s1, 0($sp)    # save $s1 on $stack

                        # sum2(a, b)

                        # sum2(c, d);

                        # sum2(e, f)

    lw   $ra, 8($sp)   # restore $ra from $stack
    lw   $s1, 4($sp)    # restore $s0 on $stack
    lw   $s0, 0($sp)    # restore $s1 on $stack
    addi $sp, $sp, 16   # move stack pointer back up to what it was when sum4 called

    jr   $ra            # return from sum4


sum2:                   # sum2 doesn't call other functions
                        # so it doesn't need to save any registers
    jr   $ra            # return from sum2

