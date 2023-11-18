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
#define usacoio                  \
	freopen("hps.in", "r", stdin); \
	freopen("hps.out", "w", stdout)
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

const int maxN = 1e5 + 1;
int dp[maxN][23][3]; // 0: Hoof, 1: Paper, 2: Scissors

int main()
{
	fastio;
	/* #ifndef ONLINE_JUDGE
		fileio;
	#endif */
	usacoio;

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		if (c == 'H')
			arr[i] = 0;
		else if (c == 'P')
			arr[i] = 1;
		else
			arr[i] = 2;
	}
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			for (int a = 0; a < 3; ++a)
			{
				if (a == arr[i])
					++dp[i][j][a];
				// 1. stay
				dp[i + 1][j][a] = max(dp[i + 1][j][a], dp[i][j][a]);
				// 2. switch
				dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][a]); // switch to hoof
				dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][a]); // switch to paper
				dp[i + 1][j + 1][2] = max(dp[i + 1][j + 1][2], dp[i][j][a]); // switch to scissors
			}
		}
	}
	ans = max(dp[n - 1][k][0], max(dp[n - 1][k][1], dp[n - 1][k][2]));
	cout << ans << endl;

	return 0;
}
