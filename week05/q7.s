# read 10 numbers into an array
# i in register $t0
main:

# i = 0
# while (i < 10) {

#   scanf("%d", &numbers[i]);
#

#   calculate &numbers[i]
#
#
#   store entered number in array

#   i++;
# }
end0:

    jr   $ra            # return

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};
