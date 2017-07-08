#include <cstdio>

int main()
{
    int no_of_words, minute_i, maximum_break;
    scanf("%d %d", &no_of_words, &maximum_break);

    int previous_minute = 0, no_of_words_on_screen = 0;
    for(int i = 1; i <= no_of_words; i++)
    {
        scanf("%d", &minute_i);
        no_of_words_on_screen = (minute_i - previous_minute <= maximum_break ? no_of_words_on_screen + 1 : 1);

        previous_minute = minute_i;
    }

    printf("%d\n", no_of_words_on_screen);
    return 0;
}
