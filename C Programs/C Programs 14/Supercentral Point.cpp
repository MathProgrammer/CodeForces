#include <cstdio>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    vector <Point> vertex(no_of_points + 1);
    for(int i = 1; i <= no_of_points; i++)
        scanf("%d %d", &vertex[i].x, &vertex[i].y);

    int no_of_supercentral_points = 0;
    for(int i = 1; i <= no_of_points; i++)
    {
        int upper = false, lower = false, right = false, left = false;

        for(int j = 1; j <= no_of_points; j++)
        {
            if(j != i)
            {
                if( (vertex[j].x == vertex[i].x) && (vertex[i].y > vertex[j].y) ) upper = true;
                if( (vertex[j].x == vertex[i].x) && (vertex[i].y < vertex[j].y) ) lower = true;
                if( (vertex[j].y == vertex[i].y) && (vertex[i].x > vertex[j].x) ) left = true;
                if( (vertex[j].y == vertex[i].y) && (vertex[i].x < vertex[j].x) ) right = true;
            }


        }//printf("Point %d\nUpper = %d, Lower = %d, left = %d, Right = %d\n", i, upper, lower, left, right);
        no_of_supercentral_points += (upper && lower && right && left);
    }

    printf("%d\n", no_of_supercentral_points);
    return 0;
}
