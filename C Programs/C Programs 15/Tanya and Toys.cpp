#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int no_of_toys, money;
    scanf("%d %d", &no_of_toys, &money);

    set <int> toy_type;
    for(int i = 1; i <= no_of_toys; i++)
    {
        int toy_i;
        scanf("%d", &toy_i);

        toy_type.insert(toy_i);
    }

    vector <int> new_toys;
    for(int toy = 1; money >= toy; toy++)
    {
        if(toy_type.count(toy) == 0)
        {
            new_toys.push_back(toy);
            money -= toy;
        }
    }

    printf("%u\n", new_toys.size());
    for(int i = 0; i < new_toys.size(); i++)
        printf("%d ", new_toys[i]);

    return 0;
}
