#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 200;
vector <int> A_indices[MAX_SIZE], B_indices[MAX_SIZE];
vector <pair <int, int> > answer;

void match(char a, char b)
{
    int common_elements = min(A_indices[a].size(), B_indices[b].size());

    while(common_elements > 0)
    {
        pair <int, int> current_pair = make_pair(A_indices[a].back(), B_indices[b].back());
        answer.push_back(current_pair);

        A_indices[a].pop_back();
        B_indices[b].pop_back();

        common_elements--;
    }
}

int main()
{
    int length;
    string A, B;
    cin >> length >> A >> B;

    for(int i = 0; i < length; i++)
    {
        A_indices[A[i]].push_back(i);

        B_indices[B[i]].push_back(i);
    }

    for(char ch = 'a'; ch <= 'z'; ch++)
        match(ch, ch);

    for(char ch = 'a'; ch <= 'z'; ch++)
        match('?', ch);

    for(char ch = 'a'; ch <= 'z'; ch++)
        match(ch, '?');

    match('?', '?');

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].first + 1 << " " << answer[i].second + 1 << "\n";
    }

    return 0;
}
