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
#define int long long

const int mod = 998244353;
int32_t main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
#endif

	int q, k;
	cin >> q >> k;
	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int p = 0; p < q; ++p)
	{
		char c;
		int x;
		cin >> c >> x;
		if (c == '+')
		{
			for (int i = k; i > 0; --i)
			{
				if (i - x < 0)
					continue;
				dp[i] += dp[i - x];
				dp[i] %= mod;
			}
		}
		else if (c == '-')
		{
			for (int i = 1; i <= k; ++i)
			{
				if (i - x < 0)
					continue;
				/* dp[i] -= dp[i - x]; */
				dp[i] += mod - dp[i - x]; // subtraction with mod
				dp[i] %= mod;
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}