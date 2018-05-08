#include <cstdio>
#include <map>
#include <vector>

typedef unsigned long long ULL;
using namespace std;


int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    map <ULL, int> present;
    vector <ULL> A(no_of_elements + 1);

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64u", &A[i]);
        present[A[i]] = true;
    }

    ULL first_element;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int comes_from_multiplication = (A[i]%2 == 0 && present[A[i]/2]);
        int comes_from_division = (A[i] <= 1e18 && present[3*A[i]]);

        if(!comes_from_multiplication && !comes_from_division)
        {
            first_element = A[i];
        }
    }

    vector <ULL> solution;
    solution.push_back(first_element);
    while(solution.size() < no_of_elements)
    {
        ULL last_element = solution.back();
        if(last_element%3 == 0 && present[last_element/3])
        {
               solution.push_back(last_element/3);
        }
        else
        {
            solution.push_back(2*last_element);
        }
    }

    for(int i = 0; i < no_of_elements; i++) printf("%I64u ", solution[i]);
    return 0;
}
