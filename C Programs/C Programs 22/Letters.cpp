#include <vector>
#include <cstdio>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <long long> A(no_of_elements + 1);
    vector <long long > sum_till(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64d", &A[i]);
        sum_till[i] = sum_till[i - 1] + A[i];
    }

    while(no_of_queries--)
    {
        long long x;
        scanf("%I64d", &x);

        int dorm_no = upper_bound(all(sum_till), x - 1) - sum_till.begin();
        long long room_no = x - sum_till[dorm_no - 1];

        printf("%d %I64d\n", dorm_no, room_no);
    }

    return 0;
}
