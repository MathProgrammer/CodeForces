#include <iostream>
#include <vector>
#include <map>

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
    
    vector <int> B(no_of_elements + 1);
    for(int j = 1; j <= no_of_elements; j++)
    {
        cin >> B[j];
    }
    
    map < pair <int, int>, int> frequency_A;
    for(int i = 1; 2*i <= no_of_elements; i++)
    {
        if(A[i] > A[no_of_elements - i + 1])
        {
            swap(A[i], A[no_of_elements - i + 1]);
        }
        
        frequency_A[make_pair(A[i], A[no_of_elements - i + 1])]++;
    }
    
    map < pair <int, int>, int> frequency_B;
    for(int i = 1; 2*i <= no_of_elements; i++)
    {
        if(B[i] > B[no_of_elements - i + 1])
        {
            swap(B[i], B[no_of_elements - i + 1]);
        }
        
        frequency_B[make_pair(B[i], B[no_of_elements - i + 1])]++;
    }
    
    int possible = true;
    
    if(no_of_elements%2 == 1)
    {
        if(A[no_of_elements/2 + 1] != B[no_of_elements/2 + 1])
        {
            possible = false;
        }
    }
    
    for(auto it = frequency_A.begin(); it != frequency_A.end(); it++)
    {
        pair <int, int> current_pair = it->first;
        
        if(frequency_A[current_pair] != frequency_B[current_pair])
        {
            possible = false;
        }
    }
    
    cout << (possible ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
