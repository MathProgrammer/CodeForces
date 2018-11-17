#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    const long long NOT_FOUND = 0;
    long long smallest_odd_prime_factor = NOT_FOUND;
    if(n%2 == 1)
    {
        for(long long i = 3; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                smallest_odd_prime_factor = i;
                break;
            }
        }

        if(smallest_odd_prime_factor == NOT_FOUND)
            smallest_odd_prime_factor = n;
    }

    long long even_operations = (n - smallest_odd_prime_factor)/2;
    long long no_of_operations = (n%2 == 1) + even_operations;

    cout << no_of_operations;
    return 0;
}
