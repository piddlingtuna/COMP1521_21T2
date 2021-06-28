# i in register $t0
main:

# i = 1

# while (i < 10) {

#
#
#   $t3 = &numbers[i]
#   $t5 = numbers[i]


#   if (numbers([i]) < 0) {
#     numbers[i] += 42
#
#   }

#   i++;
# }

    jr   $ra            # return

.data

numbers:
    .word 0 1 2 -3 4 -5 6 -7 8 9  # int numbers[10] = {0,1,2,-3,4,-5,6,-7,8,9};
