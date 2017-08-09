#include <cstdio>

int main()
{
    int digital_root, no_of_digits;
    scanf("%d %d", &no_of_digits, &digital_root);

    if(digital_root == 0 && no_of_digits > 1)
        printf("No solution\n");
    else
    {
        for(int i =no_of_digits; i >= 2; i--)
            printf("9");
        printf("%d\n", digital_root);
    }


    return 0;
}
