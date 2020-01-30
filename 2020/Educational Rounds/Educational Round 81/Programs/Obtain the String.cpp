#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin, (v).end()
using namespace std;

void solve()
{
    string S, T;
    cin >> S >> T;
    
    const int NO_OF_ALPHABETS = 26;
    
    vector <vector <int> > locations(NO_OF_ALPHABETS);
    for(int i = 0; i < S.size(); i++)
    {
        locations[S[i] - 'a'].push_back(i);
    }
    
    int operations = 1, last_matched = -1;
    
    for(int i = 0; i < T.size(); i++)
    {
        if(locations[T[i] - 'a'].size() == 0)
        {
            cout << "-1\n";
            
            return;
        }
        
        auto it = upper_bound(locations[T[i] - 'a'].begin(), locations[T[i] - 'a'].end(), last_matched);
        
        //cout << "At "<< T[i] << "\n";
        
        if(it == locations[T[i] - 'a'].end())
        {
            operations++;
            
            last_matched = locations[T[i] - 'a'][0];
        }
        else
        {
            last_matched = *it;
        }
    }
    
    cout << operations << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
