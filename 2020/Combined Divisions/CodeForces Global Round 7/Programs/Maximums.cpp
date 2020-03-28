#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    vector <int> A(no_of_elements + 1);
    vector <int> prefix_max(no_of_elements + 5, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        A[i] = B[i] + prefix_max[i];
        
        prefix_max[i + 1] = max(prefix_max[i], A[i]);
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
