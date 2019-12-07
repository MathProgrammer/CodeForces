#include <iostream>
#include <vector>

using namespace std;

int no_of_bits(long long n)
{
    int bits = 0;

    while(n)
    {
        bits += n%2;

        n /= 2;
    }

    return bits;
}

long long set_bit(long long n, int bit)
{
    n |= (1LL << bit);

    return n;
}

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL <<bit)) != 0);
}

int main()
{
    string S;
    cin >> S;

    const int NO_OF_LETTERS = 20;
    int length = S.size();
    long long max_mask = (1LL << NO_OF_LETTERS);

    vector <long long> max_distinct(max_mask, 0);
    for(int i = 0; i < S.size(); i++)
    {
        int current_mask = 0;

        for(int j = i; j < S.size(); j++)
        {
            if(is_bit_set(current_mask, S[j] - 'a'))
            {
                break;
            }

            current_mask = set_bit(current_mask, S[j] - 'a');

            max_distinct[current_mask] = j - (i - 1);

            //cout << "Max Distinct " << current_mask << " = " << max_distinct[current_mask] << "\n";
        }
    }

    for(int mask = 0; mask < max_mask; mask++)
    {
        for(int bit = 0; bit < NO_OF_LETTERS; bit++)
        {
            if(is_bit_set(mask, bit))
            {
                max_distinct[mask] = max(max_distinct[mask], max_distinct[mask^(1LL << bit)]);
            }
        }
    }

    long long answer = 0;
    for(int mask = 0; mask < max_mask; mask++)
    {
        if(max_distinct[mask] != no_of_bits(mask))
        {
            continue;
        }

        int complement = (max_mask - 1)^mask;

        answer = max(answer, max_distinct[mask] + max_distinct[complement]);
    }

    cout << answer;
    return 0;
}
