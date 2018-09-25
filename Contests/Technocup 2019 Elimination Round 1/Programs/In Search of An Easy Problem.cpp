#include <cstdio>

int main()
{
    int no_of_opinions;
    scanf("%d", &no_of_opinions);

    int is_hard = false;
    while(no_of_opinions--)
    {
        const int HARD = 1;

        int opinion;
        scanf("%d", &opinion);

        if(opinion == HARD)
            is_hard = true;
    }

    printf(is_hard ? "HARD\n" : "EASY\n");
    return 0;
}
