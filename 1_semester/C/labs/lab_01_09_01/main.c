#include <stdio.h>
#include <math.h>

#define ERR_IO 1

int main(void)
{
    double x;
    int i = 1;
    double g = 0;
    if (scanf("%lf", &x) != 1 || x < 0)
    {
        return ERR_IO;
    }
    while (x >= 0)
    {
        g += sqrt(x / i);
        i++;
        if (scanf("%lf", &x) != 1)
        {
            return ERR_IO;
        }
    }
    printf("%lf", sin(g));  
}