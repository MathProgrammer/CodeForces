#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_length(int x, int y, string &S)
{
    int length = 0;
    
    for(int i = 0; i < S.size(); i++)
    {
        if(length%2 == 0)
        {
            if(S[i] == '0' + x)
            {
                length++;
            }
        }
        else
        {
            if(S[i] == '0' + y)
            {
                length++;
            }
        }
    }
    
    if(length%2 == 1)
    {
        length--;
    }
    
    return length;
}

void solve()
{
    string S;
    cin >> S;
    
    const int NO_OF_DIGITS = 10;
    vector <int> frequency(NO_OF_DIGITS, 0);
    for(int i = 0; i < S.size(); i++)
    {
        frequency[S[i] - '0']++;
    }
    
    sort(frequency.begin(), frequency.end());
    reverse(frequency.begin(), frequency.end());
    
    int maximum_length = frequency[0];
    
    for(int i = 0; i < NO_OF_DIGITS; i++)
    {
        for(int j = 0; j < NO_OF_DIGITS; j++)
        {
            maximum_length = max(maximum_length, get_length(i, j, S));
        }
    }
    
    int minimum_deletions = S.size() - maximum_length;
    
    cout << minimum_deletions << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
