#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_LENGTH = 1e4;
vector <string> lexicographic_order;
void precompute()
{
    const int NO_OF_ALPHABETS = 26;
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        string now;

        now += (char)('a' + alpha);

        lexicographic_order.push_back(now);
    }

    for(int p = 0; lexicographic_order.size() < MAX_LENGTH; p++)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            string now = lexicographic_order[p] + (char)('a' + alpha);

            lexicographic_order.push_back(now);
        }
    }
}

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    set <string> distinct;
    for(int left = 0; left < length; left++)
    {
        string current;

        for(int right = left; right < length; right++)
        {
            current += S[right];

            distinct.insert(current);
        }
    }

    for(string current : lexicographic_order)
    {
        if(distinct.count(current) == 0)
        {
            cout << current << "\n";

            return ;
        }
    }
}

int main()
{
    precompute();

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

