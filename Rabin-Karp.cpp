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

const int d = 256;

void search(char txt[], char pat[], int q)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int i,j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (int i = 0; i < m-1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n-m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (txt[i+j] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag)
                    cout << i << " ";
            }
            if (j == m)
                cout << "Pattern found at " << i << endl;
        }
        if (i < n-m)
        {
            t = (d *(t - txt[i] * h) + txt[i+m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

void solve()
{
    // Write code here
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    int q = 101;

    search(txt,pat,q);
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
        cout << endl;
    }

    return 0;
}
