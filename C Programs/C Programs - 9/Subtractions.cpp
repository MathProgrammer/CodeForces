#include <cstdio>
#include <algorithm>

using namespace std;

int no_of_steps_in_finding_gcd(int a, int b)
{
    int m = min(a, b);
    int n = max(a, b);

    if(m == 0)
        return 0;
    else
        return n/m + no_of_steps_in_finding_gcd(m, n%m);
}

void solve()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", no_of_steps_in_finding_gcd(a, b) );
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
