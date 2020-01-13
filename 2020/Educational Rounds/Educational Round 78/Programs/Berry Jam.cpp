#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_jars;
    cin >> no_of_jars;
    
    vector <long long> A(2*no_of_jars + 1);
    for(int i = 1; i <= 2*no_of_jars; i++)
    {
        cin >> A[i];
    }
    
    int suffix_1 = 0, suffix_2 = 0;
    map <long long, int> suffix_point;
    for(int i = 2*no_of_jars; i > no_of_jars; i--)
    {
        suffix_1 += (A[i] == 1);
        suffix_2 += (A[i] == 2);
    
        suffix_point[suffix_1 - suffix_2] = i;
    }
    
    int maximum_chosen = 0;
    int prefix_1 = 0, prefix_2 = 0;
    for(int i = 0; i <= no_of_jars; i++)
    {
        prefix_1 += (A[i] == 1);
        prefix_2 += (A[i] == 2);
        
        if(prefix_1 == prefix_2)
        {
            maximum_chosen = max(maximum_chosen, i);
        }
        
        if(suffix_point[prefix_2 - prefix_1] != 0)
        {
            int chosen_here = i  + (2*no_of_jars - (suffix_point[prefix_2 - prefix_1] - 1));
            
            maximum_chosen = max(maximum_chosen, chosen_here);
        }
    }
    
    int minimum_removals = 2*no_of_jars - maximum_chosen;
    
    cout << minimum_removals << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
