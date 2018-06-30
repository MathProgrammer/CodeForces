#include <iostream>
#include <string>
#include <map>

using namespace std;

int to_integer(string S)
{
    int mask = 0;

    for(int i = S.size() - 1, bit = 0; i >= 0; i--, bit++)
    {
        if(S[i] == '1')
            mask |= (1LL << bit);
    }

    return mask;
}

int get_mask(long long n)
{
    int mask = 0;

    for(int bit = 0; n > 0; bit++)
    {
        int digit = n%10;

        if(digit%2 == 1)
            mask |= (1LL << bit);

        n /= 10;
    }

    return mask;
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    map <int, int> frequency;
    while(no_of_queries--)
    {
        const char INSERTION = '+', DELETION = '-', QUERY = '?';
        char query_type;

        cin >> query_type;

        if(query_type == INSERTION)
        {
            long long n;
            cin >> n;
            frequency[get_mask(n)]++;
        }
        else if(query_type == DELETION)
        {
            long long n;
            cin >> n;
            frequency[get_mask(n)]--;
        }
        else if(query_type == QUERY)
        {
            string mask;
            cin >> mask;
            cout << frequency[to_integer(mask)] << "\n";
        }
    }

    return 0;
}
