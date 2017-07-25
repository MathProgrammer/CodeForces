#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define MAX_LENGTH 100 + 2

int main()
{
    char players[MAX_LENGTH];
    scanf("%s", players);

    int maximum_dangerous_sequence = 1, current_dangerous_sequence = 1;
    for(int i = 1; players[i] != '\0'; i++)
    {
        current_dangerous_sequence = (players[i] == players[i - 1] ? current_dangerous_sequence + 1 : 1);
        maximum_dangerous_sequence = max(maximum_dangerous_sequence, current_dangerous_sequence);
    }

    printf(maximum_dangerous_sequence >= 7 ? "YES\n" : "NO\n");
    return 0;
}
