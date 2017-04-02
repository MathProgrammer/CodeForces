#include <stdio.h>

unsigned int find_maximum_value(short, short, short);
unsigned int maximum(unsigned int, unsigned int);

int main()
{
    short a, b, c;
    unsigned int maximum_value;
    scanf("%hu %hu %hu", &a, &b, &c);

    maximum_value = find_maximum_value(a, b, c);

    printf("%u\n", maximum_value);
    return 0;
}

unsigned int find_maximum_value(short a, short b, short c)
{
    unsigned int maximum_value = a + b + c;

    maximum_value = maximum(maximum_value, (a+b)*c);
    maximum_value = maximum(maximum_value, a+(b*c));
    maximum_value = maximum(maximum_value, a*(b+c));
    maximum_value = maximum(maximum_value, (a*b)+c);
    maximum_value = maximum(maximum_value, a*b*c);

    return maximum_value;
}

unsigned int maximum(unsigned int a, unsigned int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
