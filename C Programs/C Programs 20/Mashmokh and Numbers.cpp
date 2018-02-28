#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int n, score;
    scanf("%d %d", &n, &score);

    int minimum_score = n/2;

    if(n == 1 && score == 0) {printf("1\n"); return ;}

    if(n == 1 || score < minimum_score)
    {
        printf("-1\n");
        return 0;
    }

    int score_except_last_two = (n - 2)/2;
    int second_term = score - score_except_last_two;

    printf("%d %d ", second_term, 2*second_term);

    for(int i = 3; i <= n; i++) printf("%d ", 2*second_term + i);

    return 0;
}
