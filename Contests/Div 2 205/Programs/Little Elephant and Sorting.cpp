#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%I64d", &A[i]);

    long long no_of_additions = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] < A[i - 1])
        {
            no_of_additions += (A[i - 1] - A[i]);
        }
    }

    printf("%I64d\n", no_of_additions);
    return 0;
}
