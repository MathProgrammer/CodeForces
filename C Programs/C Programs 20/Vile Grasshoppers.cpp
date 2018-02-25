#include <cstdio>

int main()
{
    int p, y;
    scanf("%d %d", &p, &y);

    int answer = y;

    while(answer > p)
    {
        int coprime_till_p = true;

        for(int i = 2; i <= p && i*i <= y; i++)
        {
            if(answer%i == 0)
            {
                coprime_till_p = false;
                break;
            }
        }

        if(coprime_till_p) break;

        answer--;
    }


    printf("%d\n", answer == p ? -1 : answer);
    return 0;
}
