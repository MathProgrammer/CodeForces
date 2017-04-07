#include <stdio.h>
int find_counterexample(int);

int main()
{
    int n, counterexample;
    scanf("%d",&n);
    counterexample = find_counterexample(n);
    printf("%d\n",counterexample);
    return 0;
}
//Return m such that m.n + 1 is guaranteed to be composite
int find_counterexample(int n)
{
    if(n <= 2)
    {
        return 7; //7 works for both 1 and 2
    }
    else
    {
        //n(n-2) + 1 = n^2 -1, m = n - 2 always works for n > 2
        return (n-2);
    }
}
