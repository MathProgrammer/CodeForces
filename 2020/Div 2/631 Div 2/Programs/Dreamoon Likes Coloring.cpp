#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_cells, no_of_elements;
    cin >> no_of_cells >> no_of_elements;
    
    vector <int> A(no_of_elements + 5);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] + i - 1 > no_of_cells)
        {
            cout << "-1\n";
            
            return 0;
        }
    }
    
    vector <long long> suffix_sum(no_of_elements + 5, 0);
    for(int i = no_of_elements; i >= 1; i--)
    {
        suffix_sum[i] = A[i] + suffix_sum[i + 1];
    }
    
    if(suffix_sum[1] < no_of_cells)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    for(long long i = 1; i <= no_of_elements; i++)
    {
        cout << max(i, no_of_cells - suffix_sum[i] + 1) << " ";
    }
    
    cout << "\n";
    return 0;
}
