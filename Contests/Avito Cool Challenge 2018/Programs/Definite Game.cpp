#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int minimum_value = (n <= 2 ? n : 1);
    cout << minimum_value;

    return 0;
}
