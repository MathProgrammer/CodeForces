#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int index_1, index_n;
    for(int i = 1; i <= n; i++)
    {
        int element;
        scanf("%d", &element);

        if(element == 1)
            index_1 = i;
        else if(element == n)
            index_n = i;
    }

    int distance = max( max(index_1, index_n) - 1, n - min(index_1, index_n) );

    printf("%d\n", distance);
    return 0;
}
