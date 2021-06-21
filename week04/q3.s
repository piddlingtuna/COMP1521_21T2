# Print the square of a number

    .text
main:
# x,y in $t0, $t1

# printf("Enter a number: ");

# scanf("%d", x);

# if (x <= 46340) goto square;

# printf("square too big for 32 bits\n");

# goto end;

square:
# y = x * x;

# printf("%d", y);

# printf("%c", '\n');

end:
# return 0; - not quite the same

    .data
prompt:
    .asciiz "Enter a number: "
too_big:
    .asciiz "square too big for 32 bits\n"
