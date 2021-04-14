#include <iostream>
#include <vector>

using namespace std;

int no_of_bits(int mask)
{
    int bit = 0;
    while(mask)
    {
        bit += (mask%2);

        mask /= 2;
    }

    return bit;
}

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    const int SET_BITS = 6;
    vector <int> mask(no_of_elements + 1);
    for(int m = 1, i = 1; i <= no_of_elements; m++)
    {
        if(no_of_bits(m) == SET_BITS)
        {
            mask[i] = m;
            i++;
        }
    }

    const int NO_OF_BITS = 13;
    vector < vector <long long> > subset(NO_OF_BITS + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int bit = 0; bit < NO_OF_BITS; bit++)
        {
            if(is_bit_set(mask[i], bit))
            {
                subset[bit].push_back(i);
            }
        }
    }

    vector <long long> subset_OR(NO_OF_BITS + 1, 0);
    for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        if(subset[bit].size() == 0)
        {
            continue;
        }

        cout << "? " << subset[bit].size() << " ";

        for(int i = 0; i < subset[bit].size(); i++)
        {
            cout << subset[bit][i] << " ";
        }

        cout << "\n";
        cout.flush();

        cin >> subset_OR[bit];
    }

    vector <long long> answer(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int bit = 0; bit < NO_OF_BITS; bit++)
        {
            if(!is_bit_set(mask[i], bit))
            {
                answer[i] |= subset_OR[bit];
            }
        }
    }

    cout << "! ";
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}
