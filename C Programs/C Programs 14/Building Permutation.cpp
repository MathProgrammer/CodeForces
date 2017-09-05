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

    long long no_of_moves = 0;
    for(int i = 0; i < no_of_elements; i++)
        no_of_moves += abs(element[i] - (i+1) );

    printf("%I64d\n", no_of_moves);
    return 0;
}
