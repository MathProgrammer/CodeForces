#include <iostream>

using namespace std;

int count_bits(int n)
{
    int total = 0;

    while(n)
    {
        n = n >> 1;
        total++;
    }

    return total;
}

int main()
{
    int n;
    cin >> n;

    int no_of_bits = count_bits(n);

    cout << no_of_bits;
    return 0;
}
