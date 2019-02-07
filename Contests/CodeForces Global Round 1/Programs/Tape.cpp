#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct Point
{
    int position, difference;

    Point(int p, int d)
    {
        position = p, difference = d;
    }

    int operator <(const Point &P)
    {
        return (difference < P.difference);
    }
};

int main()
{
    int no_of_points, total_length, max_parts;
    cin >> no_of_points >> total_length >> max_parts;

    vector <int> A(no_of_points);
    for(int i = 0; i < no_of_points; i++)
        cin >> A[i];

    sort(all(A));

    vector <Point> D;
    for(int i = 1; i < no_of_points; i++)
        D.push_back(Point(i, A[i] - A[i - 1]));

    sort(all(D));

    vector <int> allowed(no_of_points, true);

    for(int count = 1, i = D.size() - 1; i >= 0 && count < max_parts; count++, i--)
    {
        allowed[D[i].position] = false;
    }

    int left = 0, right = 1;
    int total_length_used = 0;

    while(left < no_of_points)
    {
        while(right < no_of_points && allowed[right])
        {
            right++;
        }

        right--;

        total_length_used += (A[right] - A[left] + 1);

        left = right + 1;
        right = left + 1;
    }

    cout << total_length_used << "\n";
    return 0;
}
