#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> frequency(2*no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;
    }
    
    int maximum_teams = 0;
    for(int pair_sum = 1; pair_sum < 2*no_of_elements + 1; pair_sum++)
    {
        int max_teams_now = 0;
        
        for(int i = 1; i <= no_of_elements; i++)
        {
            if(pair_sum - i >= i)
            {
                if(i != pair_sum - i)
                {
                    max_teams_now += min(frequency[pair_sum - i], frequency[i]);
                }
                else
                {
                    max_teams_now += frequency[i]/2;
                }
            }
        }
        
        maximum_teams = max(maximum_teams, max_teams_now);
    }
    
    cout << maximum_teams << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
