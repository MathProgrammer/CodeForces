#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int is_bit_set(int n, int position)
{
    return ( (n&(1 << position)) != 0);
}

int value(char n)
{
    if('0' <= n && n <= '9') return n - '0';
    if('A' <= n && n <= 'Z') return 10 + n - 'A';
    if('a' <= n && n <= 'z') return 36 + n - 'a';
    if(n == '-')return 62;
    if(n == '_') return 63;
}

int main()
{
    string S;
    cin >> S;

    long long no_of_ways = 1;

    const int MOD = 1e9 + 7;
    for(int i = 0; i < S.size(); i++)
    {
        for(int bit = 0; bit < 6; bit++)
        {
            if(!is_bit_set(value(S[i]), bit))
            {
                no_of_ways = (no_of_ways*3)%MOD;
            }
        }
    }

    cout << no_of_ways;
    return 0;
}
