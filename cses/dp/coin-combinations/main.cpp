#include <iostream>
using namespace std;
#define int long long
const int mx = 1e6 + 5;
int dp[mx];
const int mod = 1e9 + 7;
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// ez
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= x; ++i)
	{
		for (auto j : arr)
		{
			if (i - j < 0)
				continue;
			dp[i] += dp[i - j];
			dp[i] %= mod;
		}
	}
	cout << dp[x] << endl;
	return 0;
}