#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> A(n/2 + 1);
    for(int i = 1; 2*i <= n; i++)
        cin >> A[i];

    sort(all(A));

    int black_moves = 0;
    for(int i = 1; 2*i <= n; i++)
        black_moves += abs(A[i] - (2*i - 1));

    int white_moves = 0;
    for(int i = 1; 2*i <= n; i++)
        white_moves += abs(A[i] - 2*i);

    int minimum_moves = min(black_moves, white_moves);
    cout << minimum_moves;

    return 0;
}
