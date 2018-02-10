#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int k, total_nuts, dividers, capacity;
    scanf("%d %d %d %d", &k, &total_nuts, &dividers, &capacity);

    int boxes_used = 0, nuts_stored_till_here = 0;

    while(nuts_stored_till_here < total_nuts)
    {
        boxes_used++;

        int dividers_used_in_this_box = min(dividers, k - 1);
        int nuts_in_this_box = (dividers_used_in_this_box + 1)*capacity;


        dividers -= dividers_used_in_this_box;
        nuts_stored_till_here += nuts_in_this_box;
    }

    printf("%d\n", boxes_used);
    return 0;
}
