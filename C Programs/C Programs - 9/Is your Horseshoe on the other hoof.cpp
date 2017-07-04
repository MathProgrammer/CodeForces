#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map <int, int> frequency;
    int  hoof_i, no_of_hooves = 4;

    for(int i = 1; i <= no_of_hooves;i++)
    {
        scanf("%d", &hoof_i);
        frequency[hoof_i]++;
    }

    int no_of_new_hooves = 0;
    for(map <int, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        int frequency_i = it->second;

        no_of_new_hooves += frequency_i - 1; //Keep one copy and throw the rest
    }

    printf("%d\n", no_of_new_hooves);
    return 0;
}
