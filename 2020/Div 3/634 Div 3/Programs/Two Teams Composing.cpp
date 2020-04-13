#include <iostream>
#include <vector>
#include <set>
#include <map>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
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
    
    set <int> distinct;
    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        distinct.insert(A[i]);
        frequency[A[i]]++;
    }
    
    int team_size = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int team_size_here_1 = min(distinct.size() - 1, frequency[A[i]]);
        
        int team_size_here_2 = min(distinct.size(), frequency[A[i]] - 1);
        
        int team_size_here = max(team_size_here_1, team_size_here_2);
        
        team_size = max(team_size, team_size_here);
    }
    
    cout << team_size << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
