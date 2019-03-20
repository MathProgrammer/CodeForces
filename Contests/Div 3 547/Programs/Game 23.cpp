#include <iostream>

using namespace std;

typedef unsigned long long ULL;

int exponent(ULL n, ULL divisor)
{
    int exp = 0;

    while(n%divisor == 0)
    {
        n /= divisor;

        exp++;
    }

    return exp;
}

int main()
{
    ULL target, source;
    cin >> source >> target;

    int target_power_of_2 = exponent(target, 2);
    int target_power_of_3 = exponent(target, 3);

    int source_power_of_2 = exponent(source, 2);
    int source_power_of_3 = exponent(source, 3);

    int no_of_moves = 0;

    for(int i = source_power_of_2 + 1; i <= target_power_of_2; i++)
    {
        if(source <= target/2)
        {
            source *= 2;

            no_of_moves++;
        }
    }

    for(int i = source_power_of_3 + 1; i <= target_power_of_3; i++)
    {
        if(source <= target/3)
        {
            source *= 3;

            no_of_moves++;
        }
    }

    const int IMPOSSIBLE = -1;
    cout << (source == target ? no_of_moves : IMPOSSIBLE);
    return 0;
}
