#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int NO_OF_CANDIES = 4;
    vector <int> A(NO_OF_CANDIES + 1, 0);
    for(int i = 1; i <= NO_OF_CANDIES; i++)
        cin >> A[i];

    cout << ( ( (A[1] + A[2] == A[3] + A[4]) || (A[1] + A[3] == A[2] + A[4]) || (A[1] + A[4] == A[2] + A[3])
               || (A[1] == A[2] + A[3] + A[4]) || (A[2] == A[1] + A[3] + A[4]) || (A[3] == A[1] + A[2] + A[4]) || (A[4] == A[1] + A[2] + A[3]) ) ? "YES\n" : "NO\n");
    return 0;
}
