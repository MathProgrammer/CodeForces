#include <iostream>
#include <vector>

using namespace std;

int get_grundy(int n, int k)
{
    if(n == 0)
    {
        return 0;
    }
    
    if(n == 1)
    {
        return 1;
    }
    
    if(k%2 == 0)
    {
        if(n == 2)
        {
            return 2;
        }
        
        return (n%2 == 0 ? 1 : 0);
    }
    else
    {
        if(n%2 == 1)
        {
            return (n <= 3 ? 1 : 0);
        }
        
        if(n == 2)
        {
            return 0;
        }
        
        if(n == 4)
        {
            return 2;
        }
        
        return (get_grundy(n/2, k) == 1 ? 2 : 1);
    }
}

int main()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    vector <int> grundy(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        grundy[i] = get_grundy(A[i], k);
    }
    
    int nim_sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        nim_sum ^= grundy[i];
    }
    
    cout << (nim_sum != 0 ? "Kevin" : "Nicky") << "\n";
    return 0;
}
