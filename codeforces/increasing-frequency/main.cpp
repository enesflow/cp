#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define fileio                      \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout)
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define printarr(arr, n)      \
	for (int i = 0; i < n; ++i) \
	{                           \
		cout << arr[i] << " ";    \
	}                           \
	cout << endl;
#define printvec(vec) printarr(vec, vec.size())

const int maxN = 5e5 + 5;

vector<vector<int>> arr(maxN + 1, vector<int>(1, 0));
int main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
#endif
	int n, c;
	cin >> n >> c;
	int sum[n + 1];
	sum[0] = 0;
	int mx = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		sum[i] = sum[i - 1] + (x == c ? 1 : 0);
		arr[x].push_back(i);
		arr[x][0] = arr[x][arr[x].size() - 1];
		mx = max(mx, x);
	}
	int ans = 0;
	for (int i = 1; i <= mx; ++i)
	{
		if (i == c)
			continue;
		if (arr[i].size() <= 1)
			continue;
		arr[i][0] = arr[i][1] - 1;
		// kadane's algorithm
		int max_so_far = 0, max_ending_here = 0;
		for (int j = 1; j < arr[i].size(); ++j)
		{
			int idx = arr[i][j];
			max_ending_here = max_ending_here + 1 - (sum[idx] - sum[arr[i][j - 1]]);
			if (max_ending_here <= 0) // <- not (< 0)
				max_ending_here = 1;		// not = 0
			if (max_so_far < max_ending_here)
				max_so_far = max_ending_here;
		}
		ans = max(ans, max_so_far);
	}
	cout << ans + (arr[c].size() - 1) << endl;

	return 0;
}