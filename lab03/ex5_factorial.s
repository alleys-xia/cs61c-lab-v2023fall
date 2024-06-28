.globl factorial

.data
n: .word 8

.text
# Don't worry about understanding the code in main
# You'll learn more about function calls in lecture soon
main:
    la t0, n #load address of n to register t0
    lw a0, 0(t0) # load the value of that address to a0
    jal ra, factorial # jump to function factorial and store return address to ra for use in that function

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

# factorial takes one argument:
# a0 contains the number which we want to compute the factorial of
# The return value should be stored in a0
factorial:
    # YOUR CODE HERE
    #store return address
    addi sp sp -8
    sw ra 0(sp) #store ra to stack because the next call will change the ra register(not happen if parameter register a0 is 1)
    sw a0 4(sp) #store parameter value a0 as caller
    # if a0 !=1 next call factorial
    addi t0 a0 -1
    bne t0 x0 L1
    # the return value of call factorial
    mv t0 a0
    # restore
    lw a0 4(sp)
    lw ra 0(sp)
    # n * return value
    mul a0 a0 t0
    addi sp sp 8
    # This is how you return from a function. You'll learn more about this later.
    # This should be the last line in your program.
    jr ra
L1:
    addi a0 a0 -1
    jal ra factorial
