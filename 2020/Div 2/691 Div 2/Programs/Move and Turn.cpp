#include <iostream>

using namespace std;

int main()
{
    int length;
    cin >> length;
    
    int horizontal_steps = length/2, vertical_steps = length/2;
    long long horizontal_results = (horizontal_steps + 1);
    long long vertical_results = (vertical_steps + 1);
    
    long long answer;
    
    if(length%2 == 1)
    {
        answer = (horizontal_results + 1)*(vertical_results) + (horizontal_results)*(vertical_results + 1);
    }
    else
    {
        answer = horizontal_results*vertical_results;
    }
    
    cout << answer << "\n";
    return 0;
}
