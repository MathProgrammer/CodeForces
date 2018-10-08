#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> position(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        position[A[i]] = i;

    vector <int> winner(no_of_elements + 1, 2);
    for(int i = no_of_elements; i >= 1; i--)
    {
        for(int multiple = i; multiple <= no_of_elements; multiple += i)
        {
            int backward_square = (position[i] - multiple);
            if(backward_square > 0 && A[backward_square] > i && winner[backward_square] == 2)
            {
                winner[position[i]] = 1;
            }

            int forward_square = (position[i] + multiple);
            if(forward_square <= no_of_elements && A[forward_square] > i && winner[forward_square] == 2)
            {
                winner[position[i]] = 1;
            }
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
        printf("%c", winner[i] == 1 ? 'A' : 'B');

    return 0;
}
