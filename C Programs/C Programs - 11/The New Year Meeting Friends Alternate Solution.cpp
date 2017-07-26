#include <cstdio>
#include <algorithm>

using namespace std;

#define min_3(a, b, c) min(a, min(b, c))
#define max_3(a, b, c) max(a, max(b, c))

int main()
{
    int location_1, location_2, location_3;
    scanf("%d %d %d", &location_1, &location_2, &location_3);

    int leftmost  = min_3(location_1, location_2, location_3);
    int rightmost = max_3(location_1, location_2, location_3);

    printf("%d\n", rightmost - leftmost);
    return 0;
}
