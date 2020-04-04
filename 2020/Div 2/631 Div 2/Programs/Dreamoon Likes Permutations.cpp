#include <iostream>
#include <vector>
#include <set>
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
    
    set <int> S;
    for(int i = 1; i <= no_of_elements; i++)
    {
        S.insert(i);
    }
    
    vector <int> prefix_mex(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(S.find(A[i]) != S.end())
        {
            S.erase(A[i]);
        }
        
        prefix_mex[i] = *(S.begin());
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        S.insert(i);
    }
    
    vector <int> suffix_mex(no_of_elements + 1);
    for(int i = no_of_elements; i >= 1; i--)
    {
        if(S.find(A[i]) != S.end())
        {
            S.erase(A[i]);
        }
        
        suffix_mex[i] = *(S.begin());
    }
    
    vector <pair <int, int> > answer;
    for(int i = 1; i < no_of_elements; i++)
    {
        if(prefix_mex[i] == i + 1 && suffix_mex[i + 1] == no_of_elements - i + 1)
        {
            answer.push_back(make_pair(i, no_of_elements - i));
        }
    }
    
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}

