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
#define rep(var, ini, limit) for(int var = ini; var < limit; var++)
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

// Sliding Window Algorithm
int SlidingWindow(int a[], int n, int k)
{
	if (n < k)
	{
		cout << "Invalid\n";
		return -1;
	}

	int maxsum = 0;
	for(int i = 0; i < k; i++)
		maxsum += a[i];

	int windowsum = maxsum;
	for(int i = k; i < n; i++)
	{
		windowsum += a[i] - a[i-k];
		maxsum = max(maxsum,windowsum);
	}

	return maxsum;
}

void solve()
{
	// Write code here
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	cout << SlidingWindow(a,n,k) << endl;
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
