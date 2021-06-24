
# i in register $t1
# j in register $t2

    .text
main:
# i = 1

loop0:
# if (i > 10) goto end0;

# j = 0

loop1:
# if (j >= i) goto end1;

# printf("%c", '*');

# j++

end1:
# printf("%c", '\n');

# i++

end0:
# return 0; - not quite the same
    jr $ra
