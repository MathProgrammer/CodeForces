#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_BIT = 63;

map < pair <int, long long>, int > grundy;

int is_bit_set(long long n, int bit)
{
    return ( (n & (1LL << bit)) != 0);
}

long long unset(long long n, int bit)
{
    n ^= (1LL << bit);

    return n;
}

int get_grundy(int n, long long mask)
{
    //Not possible to take more than N from this pile - Bits are 0 indexed
    for(int higher_bit = n; higher_bit < MAX_BIT; higher_bit++)
    {
        if(is_bit_set(mask, higher_bit))
        {
            mask = unset(mask, higher_bit);
        }
    }
    //cout << "State(" << n << "," << mask << ")\n";
    pair <int, long long> pair_here = make_pair(n, mask);

    if(grundy.find(pair_here) != grundy.end())
    {
        return grundy[pair_here];
    }

    vector <int> visited(MAX_BIT, false);
    for(int bit = 0; bit < n; bit++)
    {
        if(is_bit_set(mask, bit))
        {
            long long new_mask = unset(mask, bit);
            int new_state = get_grundy(n - bit - 1, new_mask); //cout << "Visited " << new_state << "\n";

            visited[new_state] = true;
        }
    }

    int mex = 0;
    for(int bit = 0; bit < MAX_BIT; bit++)
    {
        if( visited[bit])
        {
            continue;
        }

        mex = bit;
        break;
    }

    grundy[pair_here] = mex;

    return grundy[pair_here];

}

int main()
{
    int no_of_piles;
    cin >> no_of_piles;

    grundy[make_pair(0, 0)] = 0;

    int pile_xor = 0;
    for(int i = 1; i <= no_of_piles; i++)
    {
        int x;
        cin >> x;

        pile_xor ^= get_grundy(x, (1LL << x) - 1);
    }

    int second_player_win = (pile_xor == 0);
    cout << (second_player_win ? "YES" : "NO") << "\n";
    return 0;
}
