# row in $t0, col in $t1
main:
# for (int row = 0; row < 6; row++)

loop1:
# for (int col = 0; col < 12; col++)

loop2:
# printf("%c", flag[row][col])
# convert [row][col] to byte offset

# col++

end2:
# printf("%c", '\n')
# row++
   
end1:

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
