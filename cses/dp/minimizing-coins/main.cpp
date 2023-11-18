#include <iostream>
using namespace std;
const int mx = 1e6 + 5;
int dp[mx];
int main()
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
		dp[arr[i]] = 1;
	}
	for (int i = 1; i <= x; ++i)
	{
		dp[i] = 1e9;
		for (auto j : arr)
		{
			if (i - j < 0)
				continue;
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}
	if (dp[x] == 1e9)
		cout << -1 << endl;
	else
		cout << dp[x] << endl;
	return 0;
}