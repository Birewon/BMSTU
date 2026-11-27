#include <stdio.h>
#include <math.h>

#define ERR_IO 1
#define ERR_IO_T 2

int main(void)
{
    float u, a, t;
    if (scanf("%f%f%f", &u, &a, &t) != 3)
    {
        return ERR_IO; 
    }
    else if (t < 0)
    {
        return ERR_IO_T;
    }
    printf("%f\n", u * t + (a * t * t) / 2);

    return 0;
}

