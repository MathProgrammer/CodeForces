#include <iostream>
#include <string>

using namespace std;

string reverse(string A)
{
    string rev;

    for(int i = A.size() - 1; i >= 0; i--)
        rev += A[i];

    return rev;
}

int main()
{
    string A;
    cin >> A;

    string A_rev = reverse(A);
    string B = A_rev + A;

    cout << B;
    return 0;
}
