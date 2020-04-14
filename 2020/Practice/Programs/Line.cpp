#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long extended_gcd(long long A, long long B, long long &x, long long &y)
{
    if(B == 0)
    {
        x = 1;
        y = 0;
        return A;
    }

    long long x1, y1;
    long long gcd = extended_gcd(B, A%B, x1, y1);
    
    y = x1 - (A/B)*y1;
    x = y1;
    //cout << "(" << A << "," << B << ") = " << x << "," << y << "\n";
    return gcd;
}

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;

    long long X = 0, Y = 0;
    long long gcd_A_B = extended_gcd(A, B, X, Y);
    
    X *= (-C/gcd_A_B);
    Y *= (-C/gcd_A_B);
    
    if(C%gcd_A_B == 0)
        cout << X << " " << Y << "\n";
    else
        cout << "-1\n";

    return 0;
}
