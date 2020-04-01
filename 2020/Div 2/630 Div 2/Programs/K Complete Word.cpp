#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    const int NO_OF_ALPHABETS = 26;
    
    int length, period;
    cin >> length >> period;
    
    vector <vector <int> > frequency(period, vector <int> (NO_OF_ALPHABETS + 1, 0));
    string S;
    cin >> S;
    
    for(int i = 0; i < length; i++)
    {
        frequency[i%period][S[i] - 'a']++;
    }
    
    int minimum_moves = 0;
    for(int i = 0, j = period - 1; i <= j; i++, j--)
    {
        int moves_here = length;
        
        if(i == j)
        {
            int total = length/period + (length%period >= i && i > 0);
            
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                moves_here = min(moves_here, total - frequency[i][alpha]);
            }
        }
        else
        {
            int total_i = length/period + (length%period >= i && i > 0);
            int total_j = length/period + (length%period >= j);
            
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                moves_here = min(moves_here, total_i - frequency[i][alpha] + total_j - frequency[j][alpha]);
            }
        }
        //cout << "I = " << i << " J = " << j << " Moves = " << moves_here << "\n";
        minimum_moves += moves_here;
    }
    
    cout << minimum_moves << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
