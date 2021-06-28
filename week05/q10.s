# i in register $t0, x in $t4, y in $t8
    .text
main:
# i = 0

# while (i < 5) {

#
#
#   $t3 = &numbers[i]
#   x = numbers[i]

#   $t5 = 9 - i
#
#
#   $t7 = &numbers[9 - i]
#   y = numbers[9 - i]


#   numbers[i] = y
#   numbers[9 - i] = x

#   i++;
# }

    jr $ra              # return

    .data

numbers:
     .word 0 1 2 3 4 5 6 7 8 9  # int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
