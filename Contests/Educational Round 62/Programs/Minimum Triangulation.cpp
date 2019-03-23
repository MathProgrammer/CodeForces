#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int weight = 0;
    for(int i = 3; i <= n; i++)
        weight += i*(i - 1);

    cout << weight;
    return 0;
}
