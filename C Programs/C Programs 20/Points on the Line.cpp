#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    vector <int> A(n + 1, 0);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);

    sort(all(A));

    int removed_elements = n;

    for(int i = 1; i <= n; i++)
    {
        int removed_elements_to_start_at_i = i - 1, j = i;

        while(j <= n && A[j] - A[i] <= d)
            j++;

        removed_elements_to_start_at_i += (n - j + 1);

        removed_elements = min(removed_elements, removed_elements_to_start_at_i);
    }

    printf("%d\n", removed_elements);
    return 0;
}
