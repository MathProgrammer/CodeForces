#include <cstdio>
#include <cmath>

/*
b + b/(b - 1) = d

b^2 - b + b = db - d

b^2 -db + d = 0

d + root(d^2 - 4d)/2
*/

void solve()
{
    int d;
    scanf("%d", &d);

    if(d == 0)
    {
        printf("Y 0.000000 0.000000\n");
    }
    else if(d*d - 4*d < 0)
    {
        printf("N\n");
    }
    else
    {
        double b = (d + sqrt(d*d - 4*d))/2;
        double a = b/(b - 1);

        printf("Y %.10f %.10f\n", a, b);
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
