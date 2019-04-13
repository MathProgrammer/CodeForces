#include <iostream>
#define max_3(a, b, c) max(a, max(b, c))

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int score = max_3(2*A - 1, 2*B - 1, A + B);
    cout << score;
    return 0;
}
