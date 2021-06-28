# i in register $t0
main:
    li   $t0, 0         # i = 0

# while (i < 10) {

#   calculate &numbers[i]
#
#
#   load numbers[i] into $a0
#   printf("%d", numbers[i])
#

#   printf("%c", '\n');
#
#

#   i++
# }

    jr   $ra            # return

.data

numbers:
    .word 0 1 2 3 4 5 6 7 8 9  # int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
