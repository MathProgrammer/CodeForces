#include <stdio.h>

int main()
{
    int no_of_people, i, height_fence, current_height, total_width = 0;
    scanf("%d %d ",&no_of_people,&height_fence);

    for(i = 1; i <= no_of_people; i++)
    {
        scanf("%d",&current_height);
        total_width += (current_height > height_fence ? 2 : 1); //bent person has width 2
    }
    printf("%d\n",total_width);
    return 0;
}
