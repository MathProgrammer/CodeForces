#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    long long change = max(abs(A[no_of_elements] - A[no_of_elements - 1]),
                           abs(A[1] - A[2]));
    for(int i = 2; i < no_of_elements; i++)
    {
        long long new_operations = abs(A[i + 1] - A[i - 1]);
        long long old_operations = abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i]);
        
        change = max(change, old_operations - new_operations);
    }
    
    long long answer = 0;
    for(int i = 2; i <= no_of_elements; i++)
    {
        answer += abs(A[i] - A[i - 1]);
    }
    
    answer -= change;
    
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
