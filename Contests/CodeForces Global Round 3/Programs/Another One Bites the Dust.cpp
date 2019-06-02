#include <iostream>

using namespace std;

int main()
{
    long long A, B, AB;
    cin >> A >> B >> AB;

    long long answer = (B != A ? 1 + 2*AB + 2*min(A, B) : 2*min(A, B) + 2*AB);
    cout << answer;

    return 0;
}
