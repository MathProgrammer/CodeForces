#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

void solve()
{
    int no_of_segments;
    cin >> no_of_segments;
    
    vector <int> sorted_left(no_of_segments + 1), sorted_right(no_of_segments + 1);
    vector <int> left(no_of_segments + 1), right(no_of_segments + 1);
    for(int i = 1; i <= no_of_segments; i++)
    {
        cin >> left[i] >> right[i];
        
        sorted_left[i] = left[i];
        sorted_right[i] = right[i];
    }
    
    sort(all(sorted_left));
    sort(all(sorted_right));
    
    int minimum_deletions = no_of_segments;
    for(int i = 1; i <= no_of_segments; i++)
    {
        int after_right = no_of_segments - (upper_bound(all(sorted_left), right[i]) - sorted_left.begin()) + 1;
        int before_left = lower_bound(all(sorted_right), left[i]) - sorted_right.begin() - 1;
        
        //cout << "For [" << left[i] << "," << right[i] << "] Before Left = " << before_left << " and after right = " << after_right << "\n";
        int deletions_here = after_right + before_left;
        
        minimum_deletions = min(minimum_deletions, deletions_here);
    }
    
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
