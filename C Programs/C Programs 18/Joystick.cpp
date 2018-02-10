#include <cstdio>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int charge_a, charge_b;
    scanf("%d %d", &charge_a, &charge_b);

    int no_of_minutes = 0;

    while(max(charge_a, charge_b) > 1 && min(charge_a, charge_b) > 0)
    {
        if(charge_a < charge_b)
            charge_a++, charge_b -= 2;
        else
            charge_a -= 2, charge_b++;

        no_of_minutes++;
    }

    printf("%d\n", no_of_minutes);
    return 0;
}
