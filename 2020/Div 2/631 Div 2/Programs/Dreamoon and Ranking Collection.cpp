#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, x;
    cin >> no_of_elements >> x;
    
    const int MAX = 1e5;
    vector <int> used(MAX, false);
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        used[A[i]] = true;
    }
    
    int answer = 0;
    for(int i = 1; i < MAX; i++)
    {
        if(!used[i])
        {
            if(x == 0)
            {
                answer = i - 1;
                break;
            }
            else
            {
                x--;
                used[i] = true;
            }
        }
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
