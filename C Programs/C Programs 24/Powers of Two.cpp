#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(int position, int n)
{
    return ( (n&(1 << position)) != 0);
}

int main()
{
    int n, no_of_summands;
    cin >> n >> no_of_summands;

    int no_of_summands_made = 0;
    const int MAX_POWER = 32;
    vector <int> frequency(MAX_POWER, 0);

    for(int i = 0; i < MAX_POWER; i++)
    {
        if(is_bit_set(i, n))
        {
            frequency[i]++;

            no_of_summands_made++;
        }
    }

    if(no_of_summands < no_of_summands_made || no_of_summands > n)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    while(no_of_summands_made < no_of_summands)
    {
        for(int i = 1; i < MAX_POWER; i++)
        {
            if(frequency[i] > 0) //Break 2^i into 2^{i - 1} and 2^{i - 1}
            {
                frequency[i]--;
                frequency[i - 1] += 2;

                no_of_summands_made++;
                break;
            }
        }
    }

    for(int i = 0; i < MAX_POWER; i++)
    {
        for(int j = 0; j < frequency[i]; j++)
        {
            cout << (1 << i) << " ";
        }
    }

    return 0;
}
