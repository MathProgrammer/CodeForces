#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> sequence(no_of_elements);

    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &sequence[i]);

    sort(all(sequence));

    swap(sequence[0], sequence.back());

    for(unsigned int i = 0; i < sequence.size(); i++)
        printf("%d ", sequence[i]);

    return 0;
}
