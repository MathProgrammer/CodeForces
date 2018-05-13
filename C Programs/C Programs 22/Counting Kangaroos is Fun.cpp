#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_kangaroos;
    scanf("%d", &no_of_kangaroos);

    vector <int> kangaroo_size(no_of_kangaroos);
    for(int i = 0; i < no_of_kangaroos; i++)
        scanf("%d", &kangaroo_size[i]);

    sort(all(kangaroo_size));

    int no_of_pairs = 0;
    int front_i = 0, back_i = no_of_kangaroos/2;
    for( ; front_i < no_of_kangaroos/2 && back_i < no_of_kangaroos; front_i++)
    {
        while(back_i < no_of_kangaroos)
        {
            if(kangaroo_size[front_i]*2 <= kangaroo_size[back_i])
            {
                back_i++;
                no_of_pairs++;
                break;
            }
            else
            {
                back_i++;
            }
        }
    }

    int no_of_visible_kangaroos = no_of_pairs + (no_of_kangaroos - 2*no_of_pairs);
    printf("%d\n", no_of_visible_kangaroos);

    return 0;
}
