#include <iostream>
#include <algorithm>

#define all(v) (v).begin(),(v).end()
using namespace std;

void solve()
{
    int length;
    string X;
    cin >> length >> X;
    
    string A, B;
    for(int i = 0; i < X.size(); i++)
    {
        switch(X[i])
        {
            case '2' : A += '1'; B += '1'; break;
            case '1' : A += '1'; B += '0'; break;
            case '0' : A += '0'; B += '0'; break;
        }
    }
    
    for(int i = 0, is_equal = true; i < X.size(); i++)
    {
        if(is_equal)
        {
            if(A[i] != B[i])
            {
                is_equal = false;
            }
            
            continue;
        }
        
        if(A[i] == '1' && B[i] == '0')
        {
            A[i] = '0';
            B[i] = '1';
        }
        
        if(A[i] == '1' && B[i] == '1')
        {
            A[i] = '0';
            B[i] = '2';
        }
    }
    
    cout << A << "\n" << B << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
