#include <iostream>
#include <vector>
#include <algorithm>

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
    
    sort(A.begin() + 1, A.end());
    
    vector <int> answer(no_of_elements + 1);
    for(int i = no_of_elements, front = 1, back = no_of_elements; i >= 1; i--)
    {
        if(i%2 == no_of_elements%2)
        {
            answer[i] = A[back--];
        }
        else
        {
            answer[i] = A[front++];
        }
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
