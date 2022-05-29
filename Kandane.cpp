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

// Kadane's Algorithm
// Used to find Largest Sum in Contiguous Subarray

void solve()
{
	// Write code here
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];

	int max_so_far = INT_MIN, max_ending_here = 0;
	rep(i, 0, n)
	{
		max_ending_here += a[i];
		max_so_far = max(max_ending_here, max_so_far);
		if (max_ending_here < 0)
			max_ending_here = 0;
	}

	cout << max_so_far << endl;
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
