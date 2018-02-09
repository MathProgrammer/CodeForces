#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_rows, no_of_columns, difference;
    scanf("%d %d %d", &no_of_rows, &no_of_columns, &difference);

    vector <int> A(no_of_rows*no_of_columns, 0);

    set <int> remainder;

    int possible = true;
    for(int i = 0; i < no_of_rows*no_of_columns; i++)
    {
        scanf("%d", &A[i]);

        remainder.insert(A[i]%difference);
    }

    if(remainder.size() > 1)
        possible = false;

    sort(all(A));

    int middle = A.size()/2;
    int median = A[middle];

    int minimum_no_of_moves = 0;
    for(int i = 0; i < A.size(); i++)
        minimum_no_of_moves += abs(A[i] - median)/difference;

    printf("%d\n", possible ? minimum_no_of_moves : -1);
    return 0;
}
