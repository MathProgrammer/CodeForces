#include <iostream>
#include <map>

using namespace std;

map <int, int> answer;

int all_ones(int n)
{
    return ( (1 << n) - 1);
}

int no_of_bits(int n)
{
    int bit_count = 0;

    while(n)
    {
        bit_count++;

        n /= 2;
    }

    return bit_count;
}

int is_all_ones(int n)
{
    return (all_ones(no_of_bits(n)) == n);
}

void solve()
{
    int x;
    cin >> x;

    int max_gcd = (is_all_ones(x) ? answer[x] : all_ones(no_of_bits(x)));
    cout << max_gcd << "\n";
}

void precompute()
{
    answer[1] = 0;
    answer[3] = 1;
    answer[7] = 1;
    answer[15] = 5;
    answer[31] = 1;
    answer[63] = 21;
    answer[127] = 1;
    answer[255] = 85;
    answer[511] = 73;
    answer[1023] = 341;
    answer[2047] = 89;
    answer[4095] = 1365;
    answer[8191] = 1;
    answer[16383] = 5461;
    answer[32767] = 4681;
    answer[65535] = 21845;
    answer[131071] = 1;
    answer[262143] = 87381;
    answer[524287] = 1;
    answer[1048575] = 349525;
    answer[2097151] = 299593;
    answer[4194303] = 1398101;
    answer[8388607] = 178481;
    answer[16777215] = 5592405;
    answer[33554431] = 1082401;

}

int main()
{
    precompute();

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
