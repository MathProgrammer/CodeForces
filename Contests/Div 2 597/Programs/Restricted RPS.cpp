#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int total, papers, scissors, rocks;
    cin >> total >> rocks >> papers >> scissors;

    string moves;
    cin >> moves;

    int wins = 0;
    string answer;

    for(int i = 0; i < moves.size(); i++)
    {
        switch(moves[i])
        {
            case 'R':{
                         if(papers > 0)
                         {
                             wins++;
                             papers--;
                             answer += 'P';
                             break;
                         }
                         else
                         {
                             answer += 'X';
                             break;
                         }
                     }
            case 'P':{
                        if(scissors > 0)
                        {
                            wins++;
                            scissors--;
                            answer += 'S';
                            break;
                        }
                        else
                        {
                            answer += 'X';
                            break;
                        }
                     }
            case 'S':{
                        if(rocks > 0)
                        {
                            wins++;
                            rocks--;
                            answer += 'R';
                            break;
                        }
                        else
                        {
                            answer += 'X';
                            break;
                        }
                     }
        }
    }

    if(2*wins < total)
    {
        cout << "No\n";
        return;
    }

    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] != 'X')
        {
            continue;
        }

        if(rocks > 0)
        {
            answer[i] = 'R';
            rocks--;
            continue;
        }

        if(papers > 0)
        {
            answer[i] = 'P';
            papers--;
            continue;
        }

        if(scissors > 0)
        {
            answer[i] = 'S';
            scissors--;
            continue;
        }
    }

    cout << "Yes\n";
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

