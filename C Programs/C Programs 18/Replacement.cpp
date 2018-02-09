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

    if(no_of_elements == 1)
    {
        printf("%d", element[0] == 1 ? 2 : 1);
        return 0;
    }

    printf("1 ");
    for(int i = 1; i < no_of_elements - 1; i++)
        printf("%d ", element[i - 1]);

    if(element[no_of_elements - 1] == 1)
        printf("2");
    else
        printf("%d", element[no_of_elements - 2]);


    return 0;
}
