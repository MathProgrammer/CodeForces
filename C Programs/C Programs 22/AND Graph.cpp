#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = (1LL << 22);
vector <int> visited(MAX_N, false);
vector <int> is_present(MAX_N, false);

int complement(int x, int no_of_bits)
{
    return ( ( (1LL << no_of_bits) - 1) - x);
}

void dfs(int mask, int no_of_bits)
{
    if(visited[mask])
        return;

    visited[mask] = true;

    for(int bit = 0; bit < no_of_bits; bit++)
    {
        if(mask&(1LL << bit))
        {
            int submask = mask - (1LL << bit);
            dfs(submask, no_of_bits);
        }
    }

    if(is_present[mask])
        dfs(complement(mask, no_of_bits), no_of_bits);
}

int main()
{
    int no_of_bits, no_of_vertices;
    scanf("%d %d", &no_of_bits, &no_of_vertices);

    for(int i = 1; i <= no_of_vertices; i++)
    {
        int x;
        scanf("%d", &x);
        is_present[x] = true;
    }

    int no_of_components = 0;
    for(int i = 0; i < (1LL << no_of_bits); i++)
    {
        if(is_present[i] && !visited[i])
        {
            dfs(complement(i, no_of_bits), no_of_bits);
            no_of_components++;
        }
    }

    printf("%d\n", no_of_components);
    return 0;
}
