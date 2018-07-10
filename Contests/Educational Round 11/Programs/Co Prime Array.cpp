#include <cstdio>
#include <vector>

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
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    vector <int> coprime_array;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);

        if(i == 1 || gcd(coprime_array.back(), number_i) == 1)
        {
            coprime_array.push_back(number_i);
        }
        else
        {
            coprime_array.push_back(1);
            coprime_array.push_back(number_i);
        }
    }

    int no_of_operations = coprime_array.size() - no_of_numbers;

    printf("%d\n", no_of_operations);
    for(unsigned int i = 0; i < coprime_array.size(); i++)
        printf("%d ", coprime_array[i]);

    return 0;
}
