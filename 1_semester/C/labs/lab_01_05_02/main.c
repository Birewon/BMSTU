#include <stdio.h>

#define ERR_IO 1

int main(void)
{
    unsigned int n, fib_0 = 0, fib_1 = 1;
    if (scanf("%u", &n) != 1)
    {
        return ERR_IO;
    }

    for (unsigned i = 2; i <= n; i++)
    {
        unsigned temp = fib_0;
        fib_0 = fib_1;
        fib_1 = fib_1 + temp;
        if (fib_1 < temp)
        {
            return ERR_IO;
        }
    }

    if (n == 0)
    {
        printf("%u\n", n);
    }
    else
    {
        printf("%u\n", fib_1);
    }

    return 0;
}