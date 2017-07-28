#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_wires;
    scanf("%d", &no_of_wires);

    vector <int> no_of_birds_on_wire(no_of_wires + 1);
    for(int i = 1; i <= no_of_wires; i++)
        scanf("%d", &no_of_birds_on_wire[i]);

    int no_of_shots;
    scanf("%d", &no_of_shots);

    for(int i = 1; i <= no_of_shots; i++)
    {
        int wire_i, shot_bird;
        scanf("%d %d", &wire_i, &shot_bird);

        if(wire_i - 1 >= 1)
            no_of_birds_on_wire[wire_i - 1] += (shot_bird - 1);

        if(wire_i + 1 <= no_of_wires)
            no_of_birds_on_wire[wire_i + 1] += (no_of_birds_on_wire[wire_i] - shot_bird);

        no_of_birds_on_wire[wire_i] = 0;
    }

    for(int i = 1; i <= no_of_wires; i++)
        printf("%d\n", no_of_birds_on_wire[i]);

    return 0;
}
