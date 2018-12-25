#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_colours, group_size;
    scanf("%d %d", &no_of_colours, &group_size);

    const int MAX_COLOUR = 255;
    vector <int> colour(no_of_colours + 1);

    for(int i = 1; i <= no_of_colours; i++)
        scanf("%d", &colour[i]);

    vector <int> key(MAX_COLOUR + 1);

    vector <int> used(MAX_COLOUR + 1, false);

    for(int i = 1; i <= no_of_colours; i++)
    {
        int current_colour = colour[i];

        if(!used[current_colour])
        {
            int first_colour = max(0, current_colour - group_size + 1);

            while(used[first_colour] && key[first_colour] + group_size - 1 < current_colour)
                first_colour++;

            if(!used[first_colour])
                key[first_colour] = first_colour, used[first_colour] = true;

            for(int j = first_colour + 1; j <= current_colour; j++)
            {
                key[j] = key[first_colour];
                used[j] = true;
            }
        }
    }

    for(int i = 1; i <= no_of_colours; i++)
        printf("%d ", key[colour[i]]);

    return 0;
}
