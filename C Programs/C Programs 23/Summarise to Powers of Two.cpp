#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);
        frequency[A[i]]++;
    }

    int no_of_deletions = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int complement_exists = false;

        for(int power = 0; power <= 32; power++)
        {
            int complement = (1LL << power) - A[i];

            if(complement == A[i])
            {
                if(frequency[A[i]] >= 2)
                    complement_exists = true;
            }
            else if(frequency.find(complement) != frequency.end())
            {
                complement_exists = true;
            }
        }

        if(!complement_exists)
            no_of_deletions++;
    }

    printf("%d\n", no_of_deletions);
    return 0;
}
