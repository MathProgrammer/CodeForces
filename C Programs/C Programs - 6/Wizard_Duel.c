#include <stdio.h>

int main()
{
    int length_of_corridor, speed_of_Harry_spell, speed_of_voldemort_spell;
    float time_taken, distance_from_Harry;
    scanf("%d %d %d",&length_of_corridor, &speed_of_Harry_spell, &speed_of_voldemort_spell);

    //L-x = tq, x = tp therefore L = t(p + q)
    //The speed is constant. So, the spells reach their casters with the same time with which they reached their meeting point.
    //From here, the situation is exactly the same as the first spell. That means all the collisions happen at the same point.
    time_taken = length_of_corridor/(float)(speed_of_Harry_spell + speed_of_voldemort_spell);
    distance_from_Harry = time_taken*speed_of_Harry_spell;

    printf("%f\n",distance_from_Harry);
    return 0;
}
