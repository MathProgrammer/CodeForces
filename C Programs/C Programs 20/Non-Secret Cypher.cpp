#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, no_of_equal_elements;
    scanf("%d %d", &no_of_elements, &no_of_equal_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    int left = 1, right = 1;
    long long no_of_subarrays = 0;

    map <int, int> frequency;

    while(right <= no_of_elements)
    {
        frequency[A[right]]++;

        while(frequency[A[right]] == no_of_equal_elements)
        {
            no_of_subarrays += (no_of_elements - right + 1);

            frequency[A[left]]--;
            left++;
        }

        right++;
    }

    printf("%I64d\n", no_of_subarrays);
    return 0;
}
