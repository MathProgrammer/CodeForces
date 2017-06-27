#include <cstdio>

int main()
{
    int no_of_floors, no_of_flats, open, awake_people = 0;
    scanf("%d %d", &no_of_floors, &no_of_flats);

    for(int i = 1; i <= no_of_floors; i++)
    {
        for(int j = 1; j <= no_of_flats; j++)
        {
            bool is_awake = false;
            for(int window = 1; window <= 2; window++)
            {
                scanf("%d", &open);

                if(open == 1)
                    is_awake = true;
            }

            awake_people += (is_awake == true);
        }
    }

    printf("%d\n", awake_people);
    return 0;
}
