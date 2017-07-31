#include <cstdio>

int main()
{
    int length_text, speed_1, speed_2, ping_1, ping_2;
    scanf("%d %d %d %d %d", &length_text, &speed_1, &speed_2, &ping_1, &ping_2);

    int total_time_1 = speed_1*length_text + 2*ping_1;
    int total_time_2 = speed_2*length_text + 2*ping_2;

    if(total_time_1 == total_time_2)
        printf("Friendship\n");
    else
        printf(total_time_1 < total_time_2 ? "First\n" : "Second\n");
    return 0;
}
