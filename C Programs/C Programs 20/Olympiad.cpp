#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    set <int> awards;
    for(int i = 1; i <= n; i++)
    {
        int score;
        scanf("%d", &score);

        if(score > 0) awards.insert(score);
    }

    printf("%u\n", awards.size());
    return 0;
}

