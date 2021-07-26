# row in $t0, col in $t1

main:

    li $t0 0                # for (int row = 0; row < 6; row++)

loop_outer:
    bge $t0 6, end_outer    # if (row >= 6) goto end_outer;
    li $t1 0                # for (int col = 0; col < 12; col++)

loop_inner:
    bge $t1 12, end_inner
                            # convert [row][col] to byte offset
    mul $t2 $t0 12          # $t2 = row * 12
    add $t2 $t2 $t1         # $t2 = row * 12 + col
    lb $t3 flag($t2)        # load byte at flag + $t2
    li $v0 11
    move $a0 $t3
    syscall                 # printf("%c", flag[row][col])
    
    # row == 0     row == 1     row == 2
    # |xxxxxxxxxxxx|xxxxxxxxxxxx|xxxxxxxxxxxx|

    addi $t1 $t1 1          # col++;
    j loop_inner

end_inner:
   li   $a0, '\n'           # printf("%c", '\n');
   li   $v0, 11
   syscall

    addi $t0 $t0 1          # row++;
    j loop_outer
   
end_outer:

    li  $v0, 0              # return 0;
    jr  $ra

.data
flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
