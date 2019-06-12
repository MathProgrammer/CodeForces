#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long no_of_fillings  = (n%2 == 1 ? 0 : (1LL << (n/2)) );
    cout << no_of_fillings;

    return 0;
}
