#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector <int> permutation(n + 1, 0);
    for(int i = 1; i <= n; i++)
        scanf("%d", &permutation[i]);

    vector <int> ones_till(n + 1, 0);
    for(int i = 1; i <= n - 1; i++)
    {
        int digit;
        scanf("%1d", &digit);

        ones_till[i] = (digit == 1) + ones_till[i - 1];
    }

    int is_sortable = true;
    for(int i = 1; i <= n; i++)
    {
        if(permutation[i] != i)
        {
            int right = max(i, permutation[i]);
            int left = min(i, permutation[i]);

            int distance = (right - 1) - (left - 1);

            if(ones_till[right - 1] - ones_till[left - 1] != distance)
                is_sortable = false;
        }
    }

    printf(is_sortable ? "YES\n" : "NO\n");
    return 0;
}
