#include <cstdio>

#define abs(x) ( (x) > 0 ? (x) : -(x) )

int main()
{
    int number_of_cards, maximum, card_i;
    scanf("%d %d", &number_of_cards, &maximum);

    int sum = 0;
    for(int i = 1; i <= number_of_cards; i++)
    {
        scanf("%d", &card_i);
        sum += card_i;
    }

    int no_of_cards_required = 0;
    sum = abs(sum);

    if(sum != 0)
        no_of_cards_required = sum/maximum + (sum%maximum != 0);

    printf("%d\n", no_of_cards_required);
    return 0;
}
