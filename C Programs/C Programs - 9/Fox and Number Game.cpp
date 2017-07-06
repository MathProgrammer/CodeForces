#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int no_of_elements, element_i, array_gcd;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &element_i);
        array_gcd = (i == 1 ? element_i : gcd(array_gcd, element_i));
    }

    printf("%d\n", array_gcd*no_of_elements);
    return 0;
}
