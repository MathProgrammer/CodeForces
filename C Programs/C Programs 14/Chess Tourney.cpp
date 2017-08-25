#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_pairs;
    scanf("%d", &no_of_pairs);

    vector <int> player_rating(2*no_of_pairs + 1, 0);
    for(int i = 1; i <= 2*no_of_pairs; i++)
        scanf("%d", &player_rating[i]);

    sort(all(player_rating));

    printf(player_rating[no_of_pairs] < player_rating[no_of_pairs + 1] ? "YES\n" : "NO\n");
    return 0;
}
