#include <cstdio>

int choose(int n, int r)
{
    if(r > n)
        return 0;

    int answer = 1;

    for(int i = 0; i < r; i++)
        answer = (answer*(n - i))/(i + 1);

    return answer;
}

int main()
{
    const int MAX_LENGTH = 11;
    char sent_commands[MAX_LENGTH], received_commands[MAX_LENGTH];
    scanf("%s %s", sent_commands, received_commands);

    int destination = 0;
    for(int i = 0; sent_commands[i] != '\0'; i++)
        destination += (sent_commands[i] == '+' ? 1 : -1);

    int reached = 0, unrecognised_symbols = 0;
    for(int i = 0; received_commands[i] != '\0'; i++)
    {
        if(received_commands[i] == '?')
            unrecognised_symbols++;
        else
            reached += (received_commands[i] == '+' ? 1 : -1);
    }

    int remaining = destination - reached;

    int no_of_plus = 0, no_of_minus = unrecognised_symbols;

    while(no_of_plus - no_of_minus != remaining)
    {
        no_of_plus++;
        no_of_minus--;
    }

    int no_of_ways = choose(unrecognised_symbols, no_of_plus);
    int total_ways = (1 << unrecognised_symbols);

    double probability = (no_of_ways*1.0f)/(total_ways*1.0f);
    printf("%.9lf", probability);

    return 0;
}
