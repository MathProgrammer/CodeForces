#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> beauty(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> beauty[i];
    }
    
    map <int, long long> answer_for;
    for(int i = 1; i <= no_of_elements; i++)
    {
        answer_for[i - beauty[i]] += beauty[i];
    }
    
    long long answer = 0;
    for(auto it = answer_for.begin(); it != answer_for.end(); it++)
    {
        answer = max(answer, it->second);
    }
    
    cout << answer << "\n";
    return 0;
}
