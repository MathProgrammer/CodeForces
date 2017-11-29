#include <iostream>
#include <string>

using namespace std;

int main()
{
    string song;
    cin >> song;

    string word;
    for(int i = 0; i < song.length(); i++)
    {
        if(i + 2 < song.length() && song[i] == 'W' && song[i + 1] == 'U' && song[i + 2] == 'B')
        {
            i += 2;
            if(!word.empty())
            {
                cout << word << " ";
                word.clear();
            }
        }
        else
        {
            word += song[i];
        }
    }

    if(!word.empty())
        cout << word << " ";

    return 0;
}
