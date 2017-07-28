#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);

    sort(all(element));

    bool first_element_divides_all = true;
    for(int i = 1; i < no_of_elements; i++)
    {
        if(element[i]%element.front() != 0)
        {
            first_element_divides_all = false;
            break;
        }
    }

    printf("%d\n", first_element_divides_all ? element.front(): -1);
    return 0;
}
