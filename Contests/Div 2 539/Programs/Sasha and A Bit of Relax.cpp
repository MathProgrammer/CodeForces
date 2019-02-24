#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = (1 << 21), PARITY = 2;
int frequency[MAX_N][PARITY];

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    int prefix_xor = 0;
    long long good_subarrays = 0;
    memset(frequency, 0, sizeof(frequency));

    frequency[0][0] = 1;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;

        prefix_xor ^= element;

        good_subarrays += (frequency[prefix_xor][i%2]);

        frequency[prefix_xor][i%2]++;
    }

    cout << good_subarrays;
    return 0;
}
