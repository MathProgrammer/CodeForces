#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    int palindrome_possible = false;
    vector <int> frequency(no_of_elements + 1, 0);
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        frequency[A[i]]++;
        
        if(frequency[A[i]] == 3)
        {
            palindrome_possible = true;
        }
        
        if(frequency[A[i]] == 2 && (i > 1 && A[i] != A[i - 1]) )
        {
            palindrome_possible = true;
        }
    }
    
    cout << (palindrome_possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
