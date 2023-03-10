#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int likes = 0, unlikes = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        likes += (A[i] > 0);
        unlikes += (A[i] < 0);
    }

    vector <int> maximum_likes(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i <= likes)
        {
            maximum_likes[i] = maximum_likes[i - 1] + 1;
        }
        else
        {
            maximum_likes[i] = maximum_likes[i - 1] - 1;
        }
    }

    vector <int> minimum_likes(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if( (i + 1)/2 <= unlikes )
        {
            minimum_likes[i] = 1;
            minimum_likes[i + 1] = 0;
            i = i + 1;
        }
        else
        {
            minimum_likes[i] = minimum_likes[i - 1] + 1;
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << maximum_likes[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << minimum_likes[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
