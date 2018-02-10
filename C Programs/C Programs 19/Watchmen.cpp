#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_watchmen;
    scanf("%d", &no_of_watchmen);

    map <int, int> x_frequency;
    map <int, int> y_frequency;
    map <pair<int, int>, int> x_and_y_frequency;

    for(int i = 1; i <= no_of_watchmen; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        x_frequency[x]++;
        y_frequency[y]++;
        x_and_y_frequency[make_pair(x,y)]++;
    }

    long long same_x_pairs = 0;
    for(map <int, int> :: iterator it = x_frequency.begin(); it != x_frequency.end(); it++)
    {
        long long current_frequency = it->second;

        same_x_pairs += (current_frequency*(current_frequency - 1))/2;
    }

    long long same_y_pairs = 0;
    for(map <int, int> :: iterator it = y_frequency.begin(); it != y_frequency.end(); it++)
    {
        long long current_frequency = it->second;

        same_y_pairs += (current_frequency*(current_frequency - 1))/2;
    }

    long long same_x_and_y_pairs = 0;
    for(map <pair <int,int>, int> :: iterator it = x_and_y_frequency.begin(); it != x_and_y_frequency.end(); it++)
    {
        long long current_frequency = it->second;

        same_x_and_y_pairs += (current_frequency*(current_frequency - 1))/2;
    }

    long long answer = same_x_pairs + same_y_pairs - same_x_and_y_pairs;
    printf("%I64d\n", answer);
    return 0;
}
