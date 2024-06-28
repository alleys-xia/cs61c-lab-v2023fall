.globl f # this allows other files to find the function f
# f takes in two arguments:
# a0 is the value we want to evaluate f at
# a1 is the address of the "output" array (defined above).
# The return value should be stored in a0
f:
    # Your code here
    #开辟栈空间,并存储数组数
    addi sp sp -32
    sw ra 28(sp)
    li t0 5
    sw t0 24(sp)
    li t0 42
    sw t0 20(sp)
    li t0 19
    sw t0 16(sp)
    li t0 -38
    sw t0 12(sp)
    li t0 17
    sw t0 8(sp)
    li t0 61
    sw t0 4(sp)
    li t0 6
    sw t0 0(sp)
    # 获取参数 a0 并计算偏移
    # a0 的范围是 -3 到 3，我们需要将它映射到 0 到 6 的索引
    addi t2 a0 3  # t2 = a0 + 3
    slli t2 t2 2  # t2 = t2 * 4 （字节偏移）
    #通过sp+偏移量 得到绝对地址
    add t3 sp t2
    #读取栈中的数存储至返回值中
    lw a0 0(t3)
    # 恢复返回地址
    lw ra, 28(sp)
    # This is how you return from a function. You'll learn more about this later.
    # This should be the last line in your program.
    addi sp sp 32
    jr ra

