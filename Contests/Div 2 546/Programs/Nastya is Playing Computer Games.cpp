#include <iostream>
using namespace std;

int main()
{
	int no_of_holes, position;
	cin >> no_of_holes >> position;

	int movement = min(position - 1, no_of_holes - position) + no_of_holes - 1;
	int stones_thrown = no_of_holes + 1;
	int coins_picked = no_of_holes;

	int total_moves = movement + stones_thrown + coins_picked;
	cout << total_moves;

	return 0;
}
