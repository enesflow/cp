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
#define usacoio                   \
	freopen("time.in", "r", stdin); \
	freopen("time.out", "w", stdout)
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

const int max_days = 1005;
int main()
{
	fastio;
	usacoio;

	int n, m, c;
	cin >> n >> m >> c;
	int moo[n + 1];
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> moo[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int dp[max_days][n + 1];
	fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);
	// dp[i][j]:
	//  i: day
	//  j: node
	//  value: max money
	dp[0][1] = 0;
	int ans = 0;

	for (int t = 0; t < max_days; ++t)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (dp[t][i] == -1)
				continue; // cannot be reached
			for (auto v : adj[i])
			{
				dp[t + 1][v] = max(dp[t + 1][v], dp[t][i] + moo[v]);
			}
		}
		ans = max(ans, dp[t][1] - c * t * t);
	}
	cout << ans << endl;

	return 0;
}
