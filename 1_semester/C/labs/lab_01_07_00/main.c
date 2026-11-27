#include <stdio.h>
#include <math.h> 

#define ERR_IO 1

double f(double);
double s(double, double, int, double);
int main(void)
{
    double x;
    double eps;
    if (scanf("%lf%lf", &x, &eps) != 2)
    {
        return ERR_IO;
    }
    if (eps <= 0 || eps > 1)
    {
        return ERR_IO;
    }
    double res_s = s(x, eps, 1, 1);
    double res_f = f(x);
    double delta = fabs(res_f - res_s);
    double delta_2 = delta / fabs(res_f);
    printf("%lf\n%lf\n%lf\n%lf\n", res_s, res_f, delta, delta_2);
}

double f(double x)
{
    return exp(x);
}

double s(double x, double eps, int step, double cur)
{
    if (fabs(cur) < eps)
    {
        return 0.0;
    }
    return cur + s(x, eps, step + 1, cur * x / step);
}