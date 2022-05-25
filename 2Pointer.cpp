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

// 2-Pointer Algorithm

// Prefix Sum Algorithm

void solve()
{
	// Write code here
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n)
			cin >> a[i];

	cout << "Enter a number: ";
	int x;
	cin>>x;

	// 2-Pointer Algorithm
	sort(a,a+n);
	int i = 0, j = n-1;

	while (i < j)
	{
		if (a[i] + a[j] == x)
		{
			cout << "Indexes are " << i << " " << j << endl;
			return;
		}
		else if (a[i] + a[j] < x)
			i++;
		else
			j--;
	}
	cout << "Indexes not found\n";
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
