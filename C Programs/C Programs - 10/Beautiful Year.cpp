#include <cstdio>
#include <vector>

using namespace std;

int is_beautiful(int year)
{
    vector <int> digit_frequency(10, 0);
    while(year > 0)
    {
        digit_frequency[year%10]++;

        year = year/10;
    }

    for(int i = 0; i < 10; i++)
        if(digit_frequency[i] > 1)
            return false;

    return true;
}

int main()
{
    int year;
    scanf("%d", &year);

    int beautiful_year;
    for(beautiful_year = year + 1; ; beautiful_year++)
        if(is_beautiful(beautiful_year))
            break;

    printf("%d\n", beautiful_year);
    return 0;
}
