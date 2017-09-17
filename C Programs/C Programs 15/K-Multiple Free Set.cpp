#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <int> element(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);

    sort(all(element));

    int set_size = 0;
    vector <int> crossed_out(no_of_elements, false);

    for(int i = 0; i < no_of_elements; i++)
    {
        if(!crossed_out[i])
        {
            set_size++;

            if(binary_search(all(element), k*1LL*element[i]))
            {
                int index = lower_bound(all(element), k*1LL*element[i]) - element.begin();
                crossed_out[index] = true;
            }
        }
    }

    printf("%d\n", set_size);
    return 0;
}
