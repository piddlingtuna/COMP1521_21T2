# row in $t0, col in $t1
main:
# for (int row = 0; row < 6; row++)
    li $t0 0

loop_outer:
    #if (row >= 6) goto end_outer;
    bge $t0 6, end_outer
# for (int col = 0; col < 12; col++)
    li $t1 0
loop_inner:
    bge $t1 12, end_inner
# printf("%c", flag[row][col])
# convert [row][col] to byte offset
    
    mul $t2 $t0 12 # $t2 = row * 12
    add $t2 $t2 $t1 # $t2 = row * 12 + col
    #la $t5 flag
    #add $t2 $t2 $t5
    lb $t3 flag($t2) # flag + $t2
    # flag + row * 12 + col
    li $v0 11
    move $a0 $t3
    syscall
    
    row == 0     row == 1     row == 2
    |xxxxxxxxxxxx|xxxxxxxxxxxx|xxxxxxxxxxxx|
    |xxxxxx|

# col++
    addi $t1 $t1 1
    j loop_inner

end_inner:
# printf("%c", '\n')
   li   $a0, '\n'      # printf("%c", '\n')
   li   $v0, 11
   syscall
# row++
    $addi $t0 $t0 1
    j loop_outer
   
end_outer:

    li  $v0, 0         # return 0
    jr  $ra

.data
flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
