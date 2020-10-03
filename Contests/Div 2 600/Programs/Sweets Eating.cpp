#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nbSweets, maxPerDay;
	cin >> nbSweets >> maxPerDay;

	vector<int> val(nbSweets);

	for (int iSweet = 0; iSweet < nbSweets; ++iSweet) {
		cin >> val[iSweet];
	}

	sort(val.begin(), val.end());

	vector<long long> ans(nbSweets);

	long long curSum = 0;

	for (int lastTaken = 0; lastTaken < nbSweets; ++lastTaken) {
		curSum += val[lastTaken];
		ans[lastTaken] = curSum;

		if (lastTaken >= maxPerDay) {
			ans[lastTaken] += ans[lastTaken - maxPerDay];
		}

		cout << ans[lastTaken] << (lastTaken == nbSweets-1 ? '\n' : ' ');
	}

	return 0;
}
