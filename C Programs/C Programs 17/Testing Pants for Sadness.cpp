#include <cstdio>

int main()
{
    int no_of_questions;
    scanf("%d", &no_of_questions);

    long long no_of_clicks = 0;

    for(int i = 1; i <= no_of_questions; i++)
    {
        int no_of_options;
        scanf("%d", &no_of_options);

        no_of_clicks += 1 + i*1LL*(no_of_options - 1);
    }

    printf("%I64d\n", no_of_clicks);
    return 0;
}
