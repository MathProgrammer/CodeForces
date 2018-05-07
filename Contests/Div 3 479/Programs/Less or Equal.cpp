#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, position;
    scanf("%d %d", &no_of_elements, &position);

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    sort(all(A));

    int answer;
    if(position == 0)
    {
        answer = (A[1] > 1 ? 1 : -1);
    }
    else
    {
        answer = (position < no_of_elements && A[position] == A[position + 1] ? -1 : A[position]);
    }
    printf("%d\n", answer);

    return 0;
}
