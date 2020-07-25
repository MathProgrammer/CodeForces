#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int length;
    string A, B;
    cin >> length >> A >> B;
    
    for(int i = 0; i < length; i++)
    {
        if(A[i] > B[i])
        {
            cout << "-1\n";
            
            return;
        }
    }
    
    const int NO_OF_ALPHABETS = 26;
    vector <set <int> > replacements(NO_OF_ALPHABETS);
    for(int i = 0; i < length; i++)
    {
        if(A[i] != B[i])
        {
            replacements[A[i] - 'a'].insert(B[i] - 'a');
        }
    }
    
    int moves = 0;
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(replacements[alpha].size() == 0)
        {
            continue;
        }
        
        moves++;
        
        auto it = replacements[alpha].begin();
        int next_alpha = *it;
        
        for(it = replacements[alpha].begin(); it != replacements[alpha].end(); it++)
        {
            if(*it != next_alpha)
            {
                replacements[next_alpha].insert(*it);
            }
        }
    }
    
    cout << moves << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
