#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_couples;
    scanf("%d", &no_of_couples);

    vector <int> A(2*no_of_couples + 1);
    for(int i = 1; i <= 2*no_of_couples; i++)
        scanf("%d", &A[i]);

    int no_of_swaps = 0;
    for(int i = 1; i <= 2*no_of_couples; i += 2)
    {
        for(int j = 2*no_of_couples; j > i + 1; j--)
        {
            if(A[j] == A[i])
            {
                swap(A[j], A[j - 1]);
                no_of_swaps++;
            }
        }
    }

    printf("%d\n", no_of_swaps);
    return 0;
}
