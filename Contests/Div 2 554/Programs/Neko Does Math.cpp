#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL lcm(LL a, LL b)
{
    return (a*b)/__gcd(a, b);
}

void factorise(LL n, vector <int> &F)
{
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            F.push_back(i);

            if(i*i != n)
                F.push_back(n/i);
        }
    }
}

int main()
{
    LL a, b;
    cin >> a >> b;

    vector <int> factors;
    factorise(abs(b - a), factors);

    const LL oo = 1e18;
    LL minimum_lcm = (a == b ? a : oo), k = (a == b ? 0 : oo);

    for(int i = 0; i < factors.size(); i++)
    {
        int f = factors[i];

        if(a%f != b%f)
            continue;

        LL to_add = (a%f == 0 ? 0 : f - a%f);
        LL lcm = ((a + to_add)*(b + to_add))/__gcd(a + to_add, b + to_add);

        if(a%f == 0)
        {
            if(lcm <= minimum_lcm)
            {
                minimum_lcm = lcm;
                k = to_add;
            }
        }
        else
        {
            if(lcm < minimum_lcm)
            {
                minimum_lcm = lcm;
                k = to_add;
            }
        }
    }

    cout << k;
    return 0;
}
