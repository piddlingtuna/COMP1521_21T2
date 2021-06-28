main:
# int i = 0;

main__do:				# do {
# i++;

# syscall 1: print_int
#
# printf("%d", i);

# syscall 11: print_character
#
# printf("\n");

# } while (i <= 10);

#
	jr	$ra			# return 0;
