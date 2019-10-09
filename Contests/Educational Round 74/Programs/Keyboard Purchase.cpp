#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ALPHA = 21;
int neighbours[MAX_ALPHA][MAX_ALPHA], cost[1 << MAX_ALPHA];

int is_bit_set(int n, int bit)
{
    return ( (n&(1 << bit)) != 0);
}

int bit_count(int n)
{
    int count = 0;

    while(n > 0)
    {
        count += (n%2);

        n /= 2;
    }

    return count;
}

int main()
{
    int length, no_of_letters;
    string password;
    cin >> length >> no_of_letters >> password;

    memset(neighbours, 0, sizeof(neighbours));
    for(int i = 0; i + 1 < length; i++)
    {
        neighbours[password[i] - 'a'][password[i + 1] - 'a']++;
        neighbours[password[i + 1] - 'a'][password[i] - 'a']++;
    }

    int full_mask = (1 << no_of_letters) - 1;
    for(int mask = 0; mask <= full_mask; mask++)
    {
        const int oo = 1e9;
        cost[mask] = (mask == 0 ? 0 : oo);

        for(int latest_letter = 0; latest_letter < no_of_letters; latest_letter++)
        {
            if(!is_bit_set(mask, latest_letter))
            {
                continue;
            }

            int position = bit_count(mask);
            int cost_to_make_this_last = 0;

            for(int other_letter = 0; other_letter < no_of_letters; other_letter++)
            {
                if(other_letter == latest_letter)
                {
                    continue;
                }

                if(is_bit_set(mask, other_letter))
                {
                    cost_to_make_this_last += position*neighbours[latest_letter][other_letter];
                }
                else
                {
                    cost_to_make_this_last -= position*neighbours[latest_letter][other_letter];
                }
            }

            int mask_without_last = mask^(1 << latest_letter);

            cost[mask] = min(cost[mask], cost[mask_without_last] + cost_to_make_this_last);
        }
    }

    cout << cost[full_mask];
    return 0;
}
