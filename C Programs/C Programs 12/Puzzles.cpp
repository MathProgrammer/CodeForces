#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_students, no_of_puzzles;
    scanf("%d %d", &no_of_students, &no_of_puzzles);

    vector <int> no_of_pieces(no_of_puzzles);
    for(int i = 0; i < no_of_puzzles; i++)
        scanf("%d", &no_of_pieces[i]);

    sort(all(no_of_pieces));

    const int oo = 1e9;
    int minimum_difference = oo;
    for(int i = no_of_students - 1; i < no_of_puzzles; i++)
    {
        minimum_difference = min(minimum_difference, no_of_pieces[i] - no_of_pieces[i - (no_of_students - 1)]);
    }

    printf("%d\n", minimum_difference);
    return 0;
}
