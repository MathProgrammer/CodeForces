#include <cstdio>
#define min(a, b) (a < b ? a : b)

int main()
{
	const int OPEN = 1, CLOSED = 0;
	int no_of_cupboards;
	scanf("%d", &no_of_cupboards);

	int left_open_doors = 0, left_closed_doors = 0;
	int right_open_doors = 0, right_closed_doors = 0;

    while(no_of_cupboards--)
	{
		int left, right;
		scanf("%d %d", &left, &right);

		left_open_doors += (left == OPEN);
		left_closed_doors += (left == CLOSED);

		right_open_doors += (right == OPEN);
		right_closed_doors += (right == CLOSED);
	}

	int minimum_left_operations = min(left_closed_doors, left_open_doors);
	int minimum_right_operations = min(right_open_doors, right_closed_doors);

	printf("%d\n", minimum_left_operations + minimum_right_operations);

	return 0;
}
