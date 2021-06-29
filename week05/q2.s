# int i in $t0

main:
# int i = 0;
li	$t0, 0	# load immediate
		   	# $t0 = 0

#la == load address

main_do:				# do {
	# main loop code
addi $t0, $t0, 1 # $t0 = $t0 + 1
# i++;
# printf("%d", i);
	li $v0, 1 # $v0 = 1
	move $a0, $t0 # $a0 = $t0
	syscall

# printf("\n");
	li $v0, 11
	li $a0, 10, # '\n' == 10
	syscall

# } while (i <= 10);
	bgt $t0, 10, main_end
	j main_do
main_end:
# syscall 1: print_int
#
# printf("%d", i);

# syscall 11: print_character
#
# printf("\n");

# } while (i <= 10);

#
	jr	$ra			# return 0;
	#la $t0, string

	.data
string:
	.ascii "hello"
