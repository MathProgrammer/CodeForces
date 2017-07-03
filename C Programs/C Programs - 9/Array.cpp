#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    vector <int> zero; vector <int> positive; vector <int> negative;

    int no_of_elements, zero_start;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);


    sort(all(element));

    if(element.back() > 0)
    {
        positive.push_back(element.back());
        element.pop_back();

        negative.push_back(element.front());

        zero_start = 1;
    }
    else
    {
        positive.push_back(element[0]);
        positive.push_back(element[1]);

        negative.push_back(element[2]);

        zero_start = 3;
    }

    for(unsigned int i = zero_start; i < element.size(); i++)
            zero.push_back(element[i]);

    printf("1 %d\n",negative.back());

    printf("%u ", positive.size() );
    for(unsigned int i = 0; i < positive.size(); i++)
        printf("%d ",positive[i]);

    printf("\n%u ", zero.size());
    for(unsigned int i = 0; i < zero.size(); i++)
        printf("%d ",zero[i]);

    return 0;
}
