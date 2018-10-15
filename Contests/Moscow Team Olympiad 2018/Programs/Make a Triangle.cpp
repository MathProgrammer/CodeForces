#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> A(3);
    cin >> A[0] >> A[1] >> A[2];

    sort(A.begin(), A.end());

    int minutes = 0;

    if(A[0] + A[1] <= A[2])
    {
        minutes += (A[2] + 1 - A[1] - A[0]);
    }

    cout << minutes;
    return 0;
}
