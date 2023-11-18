#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	unordered_map<int, pair<int, int>> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
			{
				if (a[i] + a[j] > x)
					continue;
				pair<pair<int, int>, int> p = {{i, j}, a[i] + a[j]};
				int sum = p.second;
				int i1 = p.first.first;
				int i2 = p.first.second;
				if (m.find(x - sum) != m.end())
				{
					int j1 = m[x - sum].first;
					int j2 = m[x - sum].second;
					if (i1 != j1 && i1 != j2 && i2 != j1 && i2 != j2)
					{
						cout << i1 + 1 << " " << i2 + 1 << " " << j1 + 1 << " " << j2 + 1 << endl;
						return 0;
					}
				}
				m[sum] = {i1, i2};
			}
		}
	cout << "IMPOSSIBLE" << endl;
	return '0' - '0';
}