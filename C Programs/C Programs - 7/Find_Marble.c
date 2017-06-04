#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_of_glasses, initial_position, final_position, minimum_shuffles = 0, i;
    scanf("%d %d %d", &no_of_glasses, &initial_position, &final_position);

    int *shuffled_result = malloc((no_of_glasses + 1)*sizeof(int));
    for(i = 1; i <= no_of_glasses;  i++)
        scanf("%d", (shuffled_result + i) );

     for(i = initial_position; ; i = *(shuffled_result + i), minimum_shuffles++)
        if( (i == initial_position && minimum_shuffles!= 0) || (i == final_position) )
            break;


    printf("%d\n", (i == final_position ?  minimum_shuffles : -1) );//

    free(shuffled_result);
    return 0;
}
