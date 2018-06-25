#include <cstdio>

int main()
{
    const int NO_OF_NOTES = 5;
    int denominations[NO_OF_NOTES + 1] = {100, 20, 10, 5, 1};

    int amount;
    scanf("%d", &amount);

    int no_of_notes = 0;
    for(int i = 0; i < NO_OF_NOTES; i++)
    {
        if(denominations[i] <= amount)
            no_of_notes += amount/denominations[i];

        amount %= denominations[i];
    }

    printf("%d\n", no_of_notes);
    return 0;
}

