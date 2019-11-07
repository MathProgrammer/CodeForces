#include <iostream>
#include <vector>

using namespace std;

void factorise(long long n, vector <long long> &F)
{
    for(long long i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            F.push_back(i);

            while(n%i == 0)
            {
                n /= i;
            }
        }
    }

    if(n > 1)
    {
        F.push_back(n);
    }
}

int main()
{
    long long n;
    cin >> n;

    vector <long long> prime_divisors;
    factorise(n, prime_divisors);

    cout << (prime_divisors.size() > 1 || n == 1 ? 1 : prime_divisors[0]) << "\n";

    return 0;
}
