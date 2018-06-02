#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector <int> permutation(n + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &permutation[i]);

    int no_of_swaps = 0;
    vector <int> visited(n + 1, false);
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            int cycle_size = 0;

            for(int current = i; !visited[current]; current = permutation[current])
            {
                visited[current] = true;
                cycle_size++;
            }

            no_of_swaps += cycle_size - 1;
        }
    }

    printf(no_of_swaps%2 == (3*n)%2 ? "Petr" : "Um_nik");

    return 0;
}
