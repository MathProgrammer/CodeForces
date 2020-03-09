#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;
    
    string smallest = S, smallest_here = S;
    int best_k = 1;
    
    for(int k = 2; k <= length; k++)
    {
        for(int i = 0, j = k - 1 + i; j < length; i++, j++)
        {
            smallest_here[i] = S[j]; //cout << smallest_here[i];
        }
        //cout << "\n";
        for(int j = 0, i = length - k + 1; i < length; i++, j++)
        {
            smallest_here[i] = S[j];
        }
        
        if( (length - k + 1)%2 == 1)
        {
            reverse(smallest_here.begin() + length - k + 1, smallest_here.end());
        }
        
        //cout << "k = " << k << " S = " << smallest_here << "\n";
        
        if(smallest_here < smallest)
        {
            smallest = smallest_here;
            best_k = k;
        }
    }
    
    cout << smallest << "\n" << best_k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
