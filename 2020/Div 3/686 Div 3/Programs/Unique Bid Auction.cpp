#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    map <int, int> frequency;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        frequency[A[i]]++;
    }
    
    const int oo = 1e9 + 9;
    int winner = -1, answer = oo;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(frequency[A[i]] == 1 && A[i] < answer)
        {
            answer = A[i];
            
            winner = i;
        }
    }
    
    cout << winner << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
