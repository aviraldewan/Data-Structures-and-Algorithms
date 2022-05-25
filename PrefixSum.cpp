// Jai Shri Krishna
#include <bits/stdc++.h>
using namespace std;

// Macros
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int, int>
#define pq priority_queue
#define pii pair<int, int>
#define pis pair<int, string>
#define rep(var, ini, limit) for (int var = ini; var < limit; var++)
#define pb push_back
#define int long long
#define float double
#define endl "\n"
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

// ---------------------------------------------------------------

// Prefix Sum Algorithm

void solve()
{
	// Write code here
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n)
			cin >> a[i];

	// Creating Prefix Sum
	rep(i, 1, n)
		a[i] += a[i - 1];

	// Queries
	cout << "Enter a range for finding sum: ";
	int i, j;
	cin >> i >> j;
	if (i == 0)
		cout << a[j] << endl;
	else
		cout << a[j] - a[i - 1] << endl;
}

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	int t = 1;
	// 	cin >> t;
	rep(i, 1, t + 1)
	{
		// cout << "Case #" << i <<": ";
		solve();
		// cout << endl;
	}

	return 0;
}
