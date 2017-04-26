#include <stdio.h>

int main()
{
    int punched, trapped, trampled, mothered, total_dragons, i, harmed_dragons = 0;
    scanf("%d %d %d %d %d", &punched, &trapped, &trampled, &mothered, &total_dragons);

    for(i = 1; i <= total_dragons; i++)
    {
        if(i%punched == 0 || i%trapped == 0 || i%trampled == 0 || i%mothered == 0)
        {
            harmed_dragons++;
        }
    }
    printf("%d\n",harmed_dragons);
    return 0;
}
