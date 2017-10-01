#include <cstdio>

int main()
{
    int no_of_days;
    const int MAX_DAYS = 102;
    char flights[MAX_DAYS];
    scanf("%d %s", &no_of_days, flights);

    int flights_from_seattle = 0, flights_to_seattle = 0;
    for(int i = 1; i < no_of_days; i++)
    {
        flights_to_seattle += (flights[i - 1] == 'F' && flights[i] == 'S');
        flights_from_seattle += (flights[i - 1] == 'S' && flights[i] == 'F');
    }

    printf("%s\n", flights_from_seattle > flights_to_seattle ? "YES" : "NO");
    return 0;
}
