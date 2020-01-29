#include <iostream>

using namespace std;

int main()
{
    unsigned long long A, B;
    cin >> A >> B;
    
    //Y = X + B, A = 2X + B
    if(A < B || (A - B)%2 != 0)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    unsigned long long X = (A - B)/2, Y = A - X;
    //cout << X + Y << " " << (X^Y) << "\n";
    if(X + Y != A || (X^Y) != B)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    cout << X << " " << Y << "\n";
    
    return 0;
}
