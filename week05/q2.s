# i in register $t0

main:
	# load immediate
	# $t0 = 0
	li	$t0 0			# int i = 0;

main_do:
	# $t0 = $t0 + 1
	addi $t0 $t0 1	# i++;

	move $a0 $t0 		# $a0 = $t0
	li $v0 1 			# syscall 1: print_int
	syscall				# printf("%d" i);

    # '\n' == 10
	li $a0 10         	# print '\n; in syscall
	li $v0 11          	# syscall 11: print_character
	syscall             # printf("\n");

	bgt $t0 10 main_end # while (i <= 10);
	j main_do

main_end:
	jr	$ra				# return 0;

	.data
string:
	.ascii "hello"
