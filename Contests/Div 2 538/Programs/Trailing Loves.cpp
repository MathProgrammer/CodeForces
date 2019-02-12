#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

void factorise(vector <LL> &F, vector <int> &E, LL n)
{
    for(LL i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            int exponent = 0;

            while(n%i == 0)
            {
                n /= i;

                exponent++;
            }

            F.push_back(i);
            E.push_back(exponent);
        }
    }

    if(n > 1)
    {
        F.push_back(n);
        E.push_back(1);
    }
}

LL get_exponent_sum(LL n, LL p, int e)
{
    LL sum = 0;

    while(n > 0)
    {
        sum += n/p;

        n /= p;
    }

    return (sum/e);
}

int main()
{
    LL n, base;
    cin >> n >> base;

    vector <LL> prime_factors;
    vector <int> exponents;
    factorise(prime_factors, exponents, base);

    const LL oo = 1e18;
    LL trailing_zeroes = oo;
    for(int i = 0; i < prime_factors.size(); i++)
    {
        trailing_zeroes = min(trailing_zeroes, get_exponent_sum(n, prime_factors[i], exponents[i]));
    }

    cout << trailing_zeroes;
    return 0;
}
