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
#define usacoio(file)              \
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
#define si set<int>
#define pqi priority_queue<int>
// #define int long long
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e9;
const int inf2 = 1e18;
const int N = 2e5 + 5;
const int LOGN = 20;

// code
void solve(int case_num)
{
	// ...
}
// main
int32_t main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
// usacoio("");
#endif
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);

	return '0' - '0';
}