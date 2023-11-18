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
#define usacoio                       \
	freopen("teamwork.in", "r", stdin); \
	freopen("teamwork.out", "w", stdout)
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

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int dp[n]; // best possible scores
	fill(dp, dp + n, -1);

	for (int i = 0; i < n; ++i)
	{
		int best = arr[i];
		for (int j = i; j >= (i - k + 1) && j >= 0; --j)
		// j >= i - k + 1 means that we are only looking at the last k cows (including us)
		{
			best = max(best, arr[j]);
			if (j == 0) // if we are at the beginning, just don't add anything
				dp[i] = max(dp[i], best * (i - j + 1));
			else // otherwise, add the previous total to our group's total
				dp[i] = max(dp[i], dp[j - 1] + best * (i - j + 1));
			// we are not just adding + best to the previous one because
			// we may be the highest scored cow in our range, so we make every one in our group
			// have the max score by best * (i - j + 1)   (i - j + 1) being the number of cows in our group
		}
	}
	cout << dp[n - 1] << endl;

	return 0;
}
