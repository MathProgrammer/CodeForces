#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    const int MAX = 105;
    vector <int> frequency(MAX, 0);

    int sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;

        frequency[element]++;
        sum += element;
    }

    int minimum;
    for(int i = 1; i < MAX; i++)
    {
        if(frequency[i] > 0)
        {
            minimum = i;
            break;
        }
    }

    int answer = sum;
    for(int i = minimum; i < MAX; i++)
    {
        if(frequency[i] == 0)
            continue;

        if(i == minimum && frequency[i] == 1)
            continue;

        for(int p = 2; p <= i; p++)
        {
            if(i%p == 0)
            {
                int increase = minimum*(p - 1);
                int decrease = i - i/p;

                answer = min(answer, sum + increase - decrease);
            }
        }
    }

    cout << answer;
    return 0;
}
