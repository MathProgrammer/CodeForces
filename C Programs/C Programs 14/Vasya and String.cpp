#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define MAX_LENGTH 100000 + 2

int get_max_window_length(char string[], char changed_char, int max_changes)
{
    int max_window_length = 0, window_length = 0, no_of_changes = 0;

    for(int window_end = 0, window_start = 0; string[window_end] != '\0'; window_end++)
    {
        no_of_changes += (string[window_end] == changed_char);

        while(no_of_changes > max_changes)
        {
            no_of_changes -= (string[window_start++] == changed_char);
        }

        window_length = window_end - (window_start - 1);
        max_window_length = max(max_window_length, window_length);
    }

    return max_window_length;
}

int main()
{
    int length, max_changes;
    char string[MAX_LENGTH];
    scanf("%d %d %s", &length, &max_changes, string);

    int beauty = max(get_max_window_length(string, 'a', max_changes), get_max_window_length(string, 'b', max_changes));

    printf("%d\n", beauty);
    return 0;
}
