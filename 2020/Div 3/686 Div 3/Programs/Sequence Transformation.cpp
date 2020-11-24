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
    
    map <int, int> segment_frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] != A[i - 1])
        {
            segment_frequency[A[i]]++;
        }
    }
    
    int minimum_operations = no_of_elements;
    for(map <int, int> :: iterator it = segment_frequency.begin(); it != segment_frequency.end(); it++)
    {
        int operations_here = (it->second) + 1;
        
        if(A[1] == it->first)
        {
            operations_here--;
        }
        
        if(A[no_of_elements] == it->first)
        {
            operations_here--;
        }
        
        minimum_operations = min(minimum_operations, operations_here);
    }
    
    cout << minimum_operations << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
