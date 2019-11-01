#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> A(no_of_elements + 1, 0);
    vector <long long> cost(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64d %I64d", &A[i], &cost[i]);
    }

    const long long oo = 1e18;
    vector <vector <long long> > best(no_of_elements + 1, vector <long long> (3, 0));
    best[0][0] = 0, best[0][1] = best[0][2] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int no_of_adds = 0; no_of_adds <= 2; no_of_adds++)
        {
            best[i][no_of_adds] = oo;

            for(int no_of_previous_adds = 0; no_of_previous_adds <= 2; no_of_previous_adds++)
            {
                if(A[i] + no_of_adds != A[i - 1] + no_of_previous_adds)
                {
                    best[i][no_of_adds] = min(best[i][no_of_adds], best[i - 1][no_of_previous_adds] + no_of_adds*cost[i]);
                }
            }
        }
    }

    long long answer = oo;
    for(int no_of_adds = 0; no_of_adds <= 2; no_of_adds++)
    {
        answer = min(answer, best[no_of_elements][no_of_adds]);
    }

    printf("%I64d\n", answer);
}

int main()
{
    int no_of_tests;
    scanf("%d", &no_of_tests);

    while(no_of_tests--)
        solve();

    return 0;
}
