#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    long long p, q, r;
    scanf("%d %I64d %I64d %I64d", &no_of_elements, &p, &q, &r);

    vector <int> a(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &a[i]);

    vector <long long> max_P(no_of_elements);
    max_P[0] = p*a[0];
    for(int i = 1; i < no_of_elements; i++)
        max_P[i] = max(max_P[i - 1], p*a[i]);

    vector <long long> max_Q(no_of_elements);
    max_Q[0] = q*a[0] + p*a[0];
    for(int i = 1; i < no_of_elements; i++)
        max_Q[i] = max(max_Q[i - 1], q*a[i] + max_P[i]);

    vector <long long> max_R(no_of_elements);
    max_R[0] = r*a[0] + q*a[0] + p*a[0];
    for(int i = 1; i < no_of_elements; i++)
        max_R[i] = max(max_R[i - 1], r*a[i] + max_Q[i]);


    printf("%I64d\n", max_R[no_of_elements - 1]);

    return 0;
}
