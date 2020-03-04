#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, modulo;
    cin >> no_of_elements >> modulo;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    if(no_of_elements > modulo)
    {
        cout << "0\n";
        
        return 0;
    }
    
    long long product = 1;
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = i + 1; j <= no_of_elements; j++)
        {
            product *= abs(A[i] - A[j]);
            
            product %= modulo;
        }
    }
    
    cout << product << "\n";
    return 0;
}
