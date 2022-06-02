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

// Basic Function Defination
// Take input in array
template <class T>
void inputArray(T a[], int n)
{
    rep(i, 0, n)
        cin >> a[i];
}

// Print elements of array
template <class T>
void printArray(T a[], int n)
{
    rep(i, 0, n)
            cout << a[i] << " ";
    cout << endl;
}

// ---------------------------------------------------------------

// Dutch National Flag(DNF) Sort Algorithm

void DNFsort(int a[], int n)
{
    int low = 0, mid = 0, high = n-1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
            mid++;
        else
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
}

void solve()
{
    // Write code here
    int n = 10;
    int a[] = {0,1,1,0,2,2,1,2,1,1};

    DNFsort(a,n);

    printArray(a,n);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    rep(i, 1, t + 1)
    {
        // cout << "Case #" << i <<": ";
        solve();
        // cout << endl;
    }

    return 0;
}
