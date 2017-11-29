#include <cstdio>
#include <vector>

using namespace std;

const int MAX_ROWS = 301, MAX_COLUMNS = 301;
int visited[MAX_ROWS][MAX_COLUMNS] = {{false}};

void get_next(int &x, int &y, int columns)
{
    if( (y == 1 && visited[x][y + 1]) || (y == columns && visited[x][y - 1]) )
        x++;
    else
        if(y < columns && !visited[x][y + 1])
            y++;
        else
            y--;
}

int main()
{
    int rows, columns, no_of_tubes;
    scanf("%d %d %d", &rows, &columns, &no_of_tubes);

    vector <vector <pair <int, int> > >tubes(no_of_tubes + 1);
    int x = 1, y = 1, i = 1;

    while(x <= rows)
    {
        tubes[i].push_back(make_pair(x, y));

        if(i != no_of_tubes && tubes[i].size() == 2)
            i++;

        visited[x][y] = true;
        get_next(x, y, columns);
    }

    for(int i = 1; i <= no_of_tubes; i++)
    {
        printf("%d ", tubes[i].size());

        for(int j = 0; j < tubes[i].size(); j++)
            printf("%d %d ", tubes[i][j].first, tubes[i][j].second);

        printf("\n");
    }
    return 0;
}
