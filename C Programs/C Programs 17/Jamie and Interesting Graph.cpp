#include <cstdio>

int is_prime(int n)
{
    if(n <= 1)
        return false;

    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int find_nearest_prime(int n)
{
    int ans = n + 1;
    while(!is_prime(ans))
        ans++;

    return ans;
}

int main()
{
    int n, no_of_edges;
    scanf("%d %d", &n, &no_of_edges);

    int cost_to_n = find_nearest_prime(n - 2) - (n - 2);

    int mst_cost = cost_to_n + (n - 2);
    int min_path = mst_cost;

    printf("%d %d\n", mst_cost, min_path);

    for(int i = 1; i < n - 1; i++)
        printf("%d %d %d\n", i, i + 1, 1);

    printf("%d %d %d\n", n - 1, n, cost_to_n);

    int edges = n - 1;

    for(int u = 1; u <= n - 1 && edges < no_of_edges; u++)
    {
        for(int v = u + 2; v <= n && edges < no_of_edges; v++)
        {
            printf("%d %d %d\n", u, v, mst_cost);
            edges++;
        }
    }

    return 0;
}
