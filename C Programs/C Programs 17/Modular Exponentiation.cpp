#include <cstdio>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int answer = (n > 31 ? m : m%(1 << n));
    printf("%d ", answer);
    return 0;
}
