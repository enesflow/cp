// includes
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
// pragmas
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// macros
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define fileio                      \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout)
#define cowio(file)                \
	freopen(file ".in", "r", stdin); \
	freopen(file ".out", "w", stdout)
#define endl '\n'
#define printarr(arr, n)      \
	for (int i = 0; i < n; ++i) \
		cout << arr[i] << " ";    \
	cout << endl;
#define printauto(arr) \
	for (auto it : arr)  \
		cout << it << " "; \
	cout << endl;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define si set<int>
#define pqi priority_queue<int>
// #define int long long
// constants
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e9;
const int N = 2e5 + 5;
const int LOGN = 20;

const int MAXN = 20;
vi rev_adj[MAXN];
ll dp[1 << MAXN][MAXN];

// code
void solve(int case_num)
{
	// ...
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		rev_adj[--v].push_back(--u);
	}
	dp[1][0] = 1; // if we are 0 then to come to 0 it's 1 way
	for (int i = 3; i < (1 << n); i += 2)
	{
		// cause we don't need like 1001010, because we ain't going anywhere from node n (last node)
		if ((i & (1 << (n - 1))) && i != ((1 << n) - 1))
			continue;
		// loop over all the bits
		for (int j = 0; j < n; ++j)
		{
			if (!(i & (1 << j)))
				continue;
			// loop over all the neighbors
			int prev = i - (1 << j);
			for (auto nei : rev_adj[j])
			{
				if (i & (1 << nei)) // if nei is present in i
				{
					dp[i][j] += dp[prev][nei];
					dp[i][j] %= mod;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1] << endl;
}
// main
signed main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
#endif
	// cowio("");
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);

	return '0' - '0';
}