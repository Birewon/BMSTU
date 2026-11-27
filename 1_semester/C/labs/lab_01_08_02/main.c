#include <stdio.h>
#include <math.h>

#define ERR_IO 1
#define NOT_POS_ERR 2

int print_bin(int a)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned bit = (a >> i) & 1;
        printf("%u", bit);
    }
    return a;
}

int main(void)
{
    unsigned a;
    int n;
    if (scanf("%u%d", &a, &n) != 2)
    {
        printf("Error: IO\n");
        return ERR_IO;
    }
    if (n < 0)
    {
        printf("Error: IO\n");
        return NOT_POS_ERR;
    }
    a = (a << (n % 32)) | (a >> (32 - (n % 32)));
    printf("Result: ");
    print_bin(a);
    printf("\n");

    return 0;
}