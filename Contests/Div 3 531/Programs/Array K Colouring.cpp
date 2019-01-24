#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct bricks
{
	int value, position;

	int operator<(const bricks &b) const
	{
		return (value < b.value);
	}
};

int main()
{
	int no_of_elements, no_of_colours;
	cin >> no_of_elements >> no_of_colours;

	vector <bricks> A(no_of_elements);
	for(int i=0; i < no_of_elements ;i++)
	{
		cin >> A[i].value;
		A[i].position=i;
	}

	sort(all(A));

	vector <int> last_brick_of_colour(no_of_colours + 1, 0);
    vector <int> colour(no_of_elements + 1);

    for(int c = 0, i = 0; i < no_of_elements; i++, c = (c + 1)%no_of_colours)
    {
        if(last_brick_of_colour[c] == A[i].value)
        {
            cout << "NO\n";
            return 0;
        }

        colour[A[i].position] = c;
        last_brick_of_colour[c] = A[i].value;
    }

    cout << "YES\n";
    for(int i = 0; i < no_of_elements; i++)
        cout << colour[i] + 1 << " ";

	return 0;
}
