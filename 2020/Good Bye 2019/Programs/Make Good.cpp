#include <iostream>
#include <vector>

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
    
    long long sum = 0, array_xor = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum += A[i];
        
        array_xor ^= A[i];
    }
    
    if(array_xor == 0)
    {
        cout << "1\n";
        cout << sum + array_xor << "\n";
        return;
    }
    else
    {
        cout << "2\n";
        cout << array_xor << " " << sum + array_xor << "\n";
        return;
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
