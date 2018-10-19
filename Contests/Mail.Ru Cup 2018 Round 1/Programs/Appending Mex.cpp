#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(v) (v).begin(), (v).end()

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    int mex_so_far = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;

        if(element > mex_so_far)
        {
            cout << i;
            return 0;
        }
        else if(element == mex_so_far)
        {
            mex_so_far++;
        }
    }

    cout << "-1";
    return 0;
}
