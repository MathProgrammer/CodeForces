#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    int current_length = 0;
    vector <int> lengths;
    
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '1')
        {
            current_length++;
            
            if(i + 1 == S.size())
            {
                lengths.push_back(current_length);
            }
        }
        else
        {
            if(current_length > 0)
            {
                lengths.push_back(current_length);
                
                current_length = 0;
            }
        }
    }
    
    sort(lengths.begin(), lengths.end());
    reverse(lengths.begin(), lengths.end());
    
    int total = 0;
    for(int i = 0; i < lengths.size(); i += 2)
    {
        total += lengths[i];
    }
    
    cout << total << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
