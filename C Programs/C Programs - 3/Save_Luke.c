#include <stdio.h>

int main()
{
    float velocity_left, velocity_right, length_of_corridor, width_of_luke;
    float relative_velocity, effective_distance, max_survival_time;

    scanf("%f %f %f %f", &width_of_luke, &length_of_corridor, &velocity_left, &velocity_right);

    relative_velocity = velocity_left + velocity_right;
    effective_distance = length_of_corridor - width_of_luke;
    max_survival_time = effective_distance/relative_velocity;

    printf("%f",max_survival_time);
    return 0;
}
