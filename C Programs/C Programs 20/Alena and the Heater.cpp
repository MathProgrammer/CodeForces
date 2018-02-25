#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define max_4(a, b, c, d) max(max(a, b), max(c, d))
#define min_4(a, b, c, d) min(min(a, b), min(c, d))
#define max_5(a, b, c, d, e) max(max_4(a, b, c, d), e)
#define min_5(a, b, c, d, e) min(min_4(a, b, c, d), e)

using namespace std;

int main()
{
    int length;
    cin >> length;

    vector <int> A(length + 1);
    for(int i = 0; i < length; i++) cin >> A[i];

    string B;
    cin >> B;

    int left = -1e9, right = 1e9;

    for(int i = 4; i < length; i++)
    {
        if(B[i] == B[i - 1])
            continue;

        if(B[i] == '1')
            left = max(left, max_5(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]) + 1);

        if(B[i] == '0')
            right = min(right, min_5(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]) - 1);
    }

    cout << left << " " << right;
    return 0;
}
