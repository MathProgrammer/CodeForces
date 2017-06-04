#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
    int no_of_classes, i, continuous_breaks = 0, first_class, total_breaks = 0, current_class;
    scanf("%d", &no_of_classes);


    //Adding all the leading zeroes
    for(first_class = 1; first_class <= no_of_classes; first_class++)
    {
        scanf("%d", &current_class);

        if(current_class == 1)
            break;
        else
            total_breaks++;
    }

    for(i = first_class + 1; i <= no_of_classes; i++)
    {
        scanf("%d", &current_class);

        if(current_class == 1 && continuous_breaks >= 2)
            total_breaks += continuous_breaks;

        continuous_breaks = (current_class == 0 ? continuous_breaks + 1 : 0);
    }
    total_breaks += continuous_breaks;//Adding up all the breaks after the last class i.e. - the trailing zeroes

    printf("%d\n",(no_of_classes - total_breaks) );
    return 0;
}
