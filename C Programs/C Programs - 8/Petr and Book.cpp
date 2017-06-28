#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_pages;
    scanf("%d", &no_of_pages);

    int i;
    vector <int> pages_read_on_day(7);
    for(i = 0; i < 7; i++)
        scanf("%d", &pages_read_on_day[i]);


    i = 0;
    while(true)
    {
         no_of_pages -= pages_read_on_day[i];

        if(no_of_pages <= 0)
            break;

        i = (i + 1)%7;
    }

    printf("%d\n",i + 1);
    return 0;
}
