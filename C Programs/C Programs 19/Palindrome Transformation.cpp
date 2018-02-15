#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string A;
    int cursor;
    cin >> n >> cursor >> A;

    cursor--;
    n--;

    cursor = min(cursor, n - cursor);

    int middle = n/2;

    int leftmost = cursor, rightmost = cursor;
    for(int i = cursor; i <= middle; i++)
        if(A[i] != A[n - i])
            rightmost = i;

    for(int i = cursor; i >= 0; i--)
        if(A[i] != A[n - i])
            leftmost = i;

    int vertical_moves = 0;
    for(int i = leftmost; i <= rightmost; i++)
        vertical_moves += min(abs(A[i] - A[n - i]), 26 - abs(A[i] - A[n - i]));


    int horizontal_moves = min((cursor - leftmost) + (rightmost - leftmost), (rightmost - cursor) + (rightmost - leftmost));

    int total_moves = horizontal_moves + vertical_moves;
    cout << total_moves;
    return 0;
}
