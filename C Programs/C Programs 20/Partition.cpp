#include <cstdio>

#define abs(x) (x > 0 ? x : -x)

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int answer = 0;
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        answer += abs(element);
    }

    printf("%d\n", answer);
    return 0;
}
