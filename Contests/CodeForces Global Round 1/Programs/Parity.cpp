#include <iostream>

using namespace std;

int main()
{
    int base, no_of_digits;
    cin >> base >> no_of_digits;
    int sum_parity = 0;

    for(int d = no_of_digits - 1; d >= 0; d--)
    {
        int digit;
        cin >> digit;

        int digit_parity = digit%2;
        int base_parity = base%2;

        if(d > 0)
            sum_parity += (digit_parity*base_parity);
        else
            sum_parity += digit_parity;
    }

    cout << (sum_parity%2 == 0 ? "Even\n" : "Odd\n");
    return 0;
}
