#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;

struct song
{
    LL length, beauty;

    song(){}

    song(LL L, LL B)
    {
        length = L, beauty = B;
    }

    const int operator <(song &S)
    {
        return (beauty < S.beauty);
    }
};

int main()
{
    int no_of_songs, max_songs;
    cin >> no_of_songs >> max_songs;

    vector <song> songs(no_of_songs);
    for(int i = 0; i < no_of_songs; i++)
        cin >> songs[i].length >> songs[i].beauty;

    sort(all(songs));

    LL pleasure = 0;
    LL current_beauty, current_length = 0;
    priority_queue <LL, vector <LL>, greater<LL> > lengths;
    int current_chosen = 0;

    for(int i = no_of_songs - 1; i >= 0; i--)
    {
        current_beauty = songs[i].beauty;

        if(current_chosen >= max_songs)
        {
            current_length -= lengths.top();

            lengths.pop();
        }

        current_length += songs[i].length;
        lengths.push(songs[i].length);

        pleasure = max(pleasure, current_beauty*current_length);

        if(current_chosen < max_songs)
        {
            current_chosen++;
        }
    }

    cout << pleasure;
    return 0;
}
