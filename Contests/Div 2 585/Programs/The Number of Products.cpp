#include <iostream>
#include <vector>

using namespace std;

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> sign(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;

        sign[i] = (x > 0 ? 0 : 1);
    }

    vector <int> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = (sum_till[i - 1] + sign[i])%2;
    }

    long long no_of_zeroes = 0, no_of_ones = 0;
    for(int i = 0; i <= no_of_elements; i++)
    {
        if(sum_till[i] == 0)
        {
            no_of_zeroes++;
        }
        else
        {
            no_of_ones++;
        }
    }

    long long no_of_positive_products = choose_2(no_of_zeroes) + choose_2(no_of_ones);
    long long no_of_negative_prodcuts = choose_2(no_of_elements) + no_of_elements - no_of_positive_products;

    cout << no_of_negative_prodcuts << " " << no_of_positive_products << "\n";

    return 0;
}
