#include <stdio.h>
#include <math.h>

#define ERR_IO 1
#define ERR_VALUES -1
#define ACUTE 2
#define RIGHT 1
#define OBTUSE 0
#define EPS 1e-9

int type_of_tr(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double ab = pow(xb - xa, 2) + pow(yb - ya, 2);
    double ac = pow(xc - xa, 2) + pow(yc - ya, 2);
    double bc = pow(xc - xb, 2) + pow(yc - yb, 2);

    if (ab < EPS || ac < EPS || bc < EPS)
    {
        return ERR_VALUES;
    }
    else if (sqrt(ab) + sqrt(ac) <= sqrt(bc) + EPS || sqrt(ab) + sqrt(bc) <= sqrt(ac) + EPS || sqrt(ac) + sqrt(bc) <= sqrt(ab) + EPS)
    {
        return ERR_VALUES;
    }

    if ((ab + ac < bc) || (ab + bc < ac) || (ac + bc < ab))
    {
        return ACUTE;
    }
    else if (fabs(ab + ac - bc) < EPS || fabs(ab + bc - ac) < EPS || fabs(ac + bc - ab) < EPS)
    {
        return RIGHT;
    }
    else
    {
        return OBTUSE;
    }
}

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    if (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
    {
        return ERR_IO;
    }
    

    int res = type_of_tr(xa, ya, xb, yb, xc, yc);
    if (res != ERR_VALUES)
    {
        printf("%d\n", res);
    }
    else
    {
        return ERR_IO;
    }

    return 0;
}