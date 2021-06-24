### Compute factorials -- no functions (except main)

    .text
main:

# n = 0

# printf("n  = ")

# scanf("%d", into $v0)

# fac = 1

main_fac_init:
# i = 1

main_fac_cond:
# i <= n  -->  if (i > n) break

# fac = fac * i

main_fac_step:
# i++

main_fac_f:
# printf("n! = ")

# assume $s2 holds n!

# printf("%d", fac)

# printf("\n")

# return 0; - not quite the same
    jr $ra

    .data

msg1:   .asciiz "n  = "
msg2:   .asciiz "n! = "
eol:    .asciiz "\n"
