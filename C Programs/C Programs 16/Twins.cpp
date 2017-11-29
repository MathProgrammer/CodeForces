#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_coins;
    scanf("%d", &no_of_coins);

    int total = 0;
    vector <int> coin(no_of_coins);
    for(int i = 0; i < no_of_coins; i++)
    {
        scanf("%d", &coin[i]);
        total += coin[i];
    }

    sort(all(coin));

    int no_of_coins_taken = 0, sum_of_taken = 0;
    for(int i = no_of_coins - 1; i >= 0 && sum_of_taken <= total ; i--)
    {
        sum_of_taken += coin[i];
        total -= coin[i];

        no_of_coins_taken++;
    }

    printf("%d\n", no_of_coins_taken);
    return 0;
}
