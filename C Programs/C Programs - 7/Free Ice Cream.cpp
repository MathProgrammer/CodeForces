#include <stdio.h>

int main()
{
    int no_of_people, distressed_kids = 0;
    long long ice_cream;
    scanf("%d %I64d", &no_of_people, &ice_cream);

    for(int i = 1; i <= no_of_people; i++)
    {
        char action;
        int amount;
        scanf(" %c %d", &action, &amount);

        if(action == '+')
            ice_cream += amount;
        else
            if(amount > ice_cream)
                distressed_kids++;
            else
                ice_cream -= amount;
    }
    printf("%I64d %d\n", ice_cream, distressed_kids);
}
