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

// Linked List
// Creation
// Insertion
// Deletion
// Finding node with specific value

// Sturcture of Node in Linked List
typedef struct node
{
    int data;
    struct node *next;
} node;

// Function to insert value in nodes
node* insertNodes(node *head, int n)
{
    if (n == 0)
        return NULL;

    node* current = new node();
    int data;
    cout << "Enter data of node: ";
    cin >> data;
    current->data = data;
    current->next = insertNodes(current,n-1);

    return current;
}

// Print value of nodes
void printNodes(node* head)
{
    node* curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr=curr->next;
    }
    cout << "NULL" << endl;
}

// Delete all nodes from linked list
void deleteList(node** head)
{
    node* curr = *head;
    node* next;
    while (curr != NULL)
    {
        next = curr->next;
        delete(curr);
        curr = next;
    }

    *head = NULL;

    cout << "Linked List Deleted\n";
}

void solve()
{
    // Write code here
    int n;
    cout << "Number of Nodes: ";
    cin >> n;

    node *head = new node();

    // Insert nodes
    head = insertNodes(head, n);

    // Print nodes
    printNodes(head);

    // Delete List
    deleteList(&head);
}

signed main()
{
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
