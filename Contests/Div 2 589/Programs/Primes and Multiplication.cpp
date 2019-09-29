#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

LL get_exponent(LL n, LL p)
{
    LL exponent = 0;
    LL temp_p = p;

    while(n > 0)
    {
        exponent += n/p;

        n /= p;
    }

    return exponent;
}

void factorise(LL n, vector <LL> &P)
{
    for(LL i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            P.push_back(i);

            while(n%i == 0)
            {
                n /= i;
            }
        }
    }

    if(n > 1)
    {
        P.push_back(n);
    }
}

LL power_mod(LL n, LL power, LL mod)
{
    LL result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*n)%mod;

        n = (n*n)%mod;
        power = power >> 1;
    }

    return result;
}

int main()
{
    LL x, n;
    cin >> x >> n;

    vector <LL> prime_factors;
    factorise(x, prime_factors);

    const LL MOD = 1e9 + 7;
    LL answer = 1;
    for(int i = 0; i < prime_factors.size(); i++)
    {
        LL exponent = get_exponent(n, prime_factors[i]);

        answer *= power_mod(prime_factors[i], exponent, MOD);

        answer %= MOD;
    }

    cout << answer << "\n";
    return 0;
}
