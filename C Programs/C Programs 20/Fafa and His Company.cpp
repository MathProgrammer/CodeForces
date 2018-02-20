#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int answer = 1;
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            answer += (i*i == n ? 1 : 2);


    printf("%d\n", answer);
    return 0;
}
