#include <cstdio>

int main()
{
    int originals, copies;
    scanf("%d %d", &copies, &originals);

    originals--;

    printf( (originals == 0 && copies == 0) || (originals >= 1 && copies >= originals && (copies - originals)%2 == 0) ? "Yes\n" : "No\n");
    return 0;
}
