#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    int num;
    if (scanf("%d", &num) != 1)
    {
        return 1;
    } 
    else if (abs(num) > 999 || abs(num) < 100)
    {
        return 2;
    }

    int res = abs((num % 10) * ((num / 10) % 10) * (num / 100));
    printf("%d", res);   

    return 0;
}