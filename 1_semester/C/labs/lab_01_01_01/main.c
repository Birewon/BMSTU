#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main(void)
{
    double a, b, deg, max_s, min_s, S;
    scanf("%lf%lf%lf", &a, &b, &deg);
    max_s = a;
    min_s = b;
    if (b > a){
	    max_s = b;
        min_s = a;
    }
    S = tan(deg / 180 * PI) * (max_s - min_s) / 2 * (a + b) / 2;
    printf("%lf", S);

    return 0;
}
