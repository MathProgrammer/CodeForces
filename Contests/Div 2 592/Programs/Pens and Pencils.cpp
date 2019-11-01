#include <iostream>
#include <vector>

using namespace std;

int ceil(int n, int d)
{
    return (n/d + (n%d != 0));
}

void solve()
{
    int lectures, practicals, pen_limit, pencil_limit, bag_capacity;
    cin >> lectures >> practicals >> pen_limit >> pencil_limit >> bag_capacity;

    int pens_required = ceil(lectures, pen_limit);
    int pencils_required = ceil(practicals, pencil_limit);

    if(pens_required + pencils_required <= bag_capacity)
    {
        cout << pens_required << " " << pencils_required << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
