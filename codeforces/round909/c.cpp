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
#define endl '\n'

// code
void solve(int case_num)
{
	// ...
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int msf = INT_MIN, meh = 0;
	int pr = 2;
	for (int i = 0; i < n; ++i)
	{
		bool ok = ((abs(arr[i] % 2)) != pr);
		if (!ok)
			meh = 0;
		meh += arr[i];
		msf = max(msf, meh);
		if (meh < 0)
		{
			meh = 0;
			pr = 2;
		}
		else
			pr = abs(arr[i] % 2);
	}
	cout << msf << endl;
}
// main
int32_t main()
{
	fastio;
#ifndef ONLINE_JUDGE
	fileio;
#endif
	// cowio("");
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);

	return '0' - '0';
}