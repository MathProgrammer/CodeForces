#include <cstdio>

int main()
{
    int no_of_buttons;
    scanf("%d", &no_of_buttons);

    int no_of_open_buttons = 0;
    for(int i = 1; i <= no_of_buttons; i++)
    {
        int button_i;
        scanf("%d", &button_i);

        no_of_open_buttons += (button_i == 0);
    }

    bool fashionable = (no_of_buttons > 1 && no_of_open_buttons == 1) || (no_of_buttons == 1 && no_of_open_buttons == 0);
    printf(fashionable ? "YES\n" : "NO\n");
    return 0;
}
