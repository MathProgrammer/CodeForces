#include <iostream>
#include <string>

using namespace std;

int main()
{
    string borze_code, translation;
    cin >> borze_code;

    for(unsigned int i = 0; i < borze_code.size(); i++)
    {
        if(borze_code[i] == '.')
            translation += '0';
        else if(borze_code[i] == '-')
        {
            if(borze_code[i + 1] == '.')
                translation += '1';
            else if(borze_code[i + 1] == '-')
                translation += '2';

            i++;
        }
    }

    cout << translation;
    return 0;
}
