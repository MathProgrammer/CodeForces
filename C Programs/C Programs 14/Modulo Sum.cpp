#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, modulo;
    scanf("%d %d", &no_of_elements, &modulo);

    typedef vector <int> v_int;
    vector <v_int> remainder_possible(modulo + 1, v_int(modulo, false));

    int last_element = min(no_of_elements, modulo);
    for(int i = 1; i <= last_element; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        for(int remainder = 0; remainder < modulo; remainder++)
        {
            if(remainder_possible[i - 1][remainder])
            {
                int remainder_after_adding = (remainder + element_i)%modulo;
                remainder_possible[i][remainder_after_adding] = true;

                remainder_possible[i][remainder] = true;
            }
        }

        remainder_possible[i][element_i%modulo] = true;
    }

    printf(no_of_elements > modulo || remainder_possible[last_element][0] ? "YES\n" : "NO\n");

    return 0;
}
