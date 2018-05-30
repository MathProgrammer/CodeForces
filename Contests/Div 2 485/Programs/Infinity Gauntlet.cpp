#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map <string, string> power;
    power["red"] = "Reality";
    power["purple"] = "Power";
    power["green"] = "Time";
    power["yellow"] = "Mind";
    power["orange"] = "Soul";
    power["blue"] = "Space";

    map <string, int> present;

    int no_of_names;
    cin >> no_of_names;

    while(no_of_names--)
    {
        string colour;
        cin >> colour;

        present[colour] = true;
    }

    vector <string> answer;
    for(map <string, string> :: iterator it = power.begin(); it != power.end(); it++)
    {
        if(!present[it->first])
            answer.push_back(it->second);
    }

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";

    return 0;
}

