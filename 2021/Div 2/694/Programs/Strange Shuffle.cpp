#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int ask(int i)
{
    int answer;
    cout << "? " << i << "\n";
    cout.flush();
    cin >> answer;
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_elements, k;
    cin >> no_of_elements >> k;

    int block_size = floor(sqrt(no_of_elements));
    int first_greater = 0;
    for(int round = 1; round <= 2 && first_greater == 0; round++)
    {
        for(int i = 1; i <= block_size && first_greater == 0; i++)
        {
            int cards = ask(i*block_size);

            if(cards > k)
            {
                first_greater = i*block_size;
            }
        }
    }

    //A[i - L] > K and A[i - R] <= K
    int left = 0, right = no_of_elements - 1;
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        int check = (first_greater - 1 - mid + no_of_elements)%no_of_elements + 1;

        int cards = ask(check);

        if(cards > k)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    int impostor = (first_greater - 1 - right + no_of_elements)%no_of_elements + 1;
    cout << "! " << impostor << "\n";
    return 0;
}
