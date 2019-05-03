//这是一个判断计算机字节序的demo
#include <stdio.h>
void byteorder()
{
    union
    {
        short value;
        char union_bytes[sizeof(short)];
    }test;
    test.value = 0x0102;
    if ((test.union_bytes[0] == 1)&& (test.union_bytes[1] == 2))
    {
        //大端就是把一个整数的高位放在内存的高位（这里在vs中可以在监视中查看内存）
        printf("这是大端");
    } else if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)) {
        //小端就是把一个整数的高位放在内存的低位
        printf("这是小端");
    } else {
        perror("unkonw: ");
    }
}

int main()
{
    byteorder();
    return 0;
}
