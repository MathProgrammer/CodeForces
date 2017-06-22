#include <stdio.h>
#include <vector>
#define INFINITY 1e9

using namespace std;

int main()
{
    int number_of_cells, destination;
    scanf("%d %d", &number_of_cells, &destination);

    vector <int> number_of_jumps(number_of_cells);
    vector <int> visited(number_of_cells + 1, false);

    for(int i = 1; i <= number_of_cells - 1; i++)
        scanf("%d", &number_of_jumps[i]);

    number_of_jumps[number_of_cells] = INFINITY;

    for(int next_cell = 1; next_cell <= number_of_cells; next_cell += number_of_jumps[next_cell])
        visited[next_cell] = true;

    printf(visited[destination] ? "YES\n" : "NO\n");

    return 0;
}
