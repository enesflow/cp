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

const int mod = 1e9 + 7;
int main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
#endif

	// well this is a classic and easy problem
	// it was just on usaco so i decided to do it the 5325th time
	int n;
	cin >> n;
	int dp[n + 1];

	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 0;
		for (int j = 1; j <= 6; ++j)
		{
			if (i - j >= 0)
				dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	cout << dp[n] << endl;

	return 0;
}