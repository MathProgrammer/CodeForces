#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct info
{
    int two, three;
    unsigned long long number;
};

int compare(const info &A, const info &B)
{
    if(A.two < B.two || A.three > B.three)
        return true;
    else
        return false;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <info> A(no_of_elements);

    for(int i = 0; i < no_of_elements; i++)
    {
        unsigned long long element;
        scanf("%I64u", &element);

        A[i].number = element;
        A[i].two = 0, A[i].three = 0;

        while(element%2 == 0) A[i].two++, element /= 2;
        while(element%3 == 0) A[i].three++, element /= 3;
    }

    sort(all(A), compare);
    for(int i = 0; i < no_of_elements; i++) printf("%I64u ", A[i].number);

    return 0;
}

