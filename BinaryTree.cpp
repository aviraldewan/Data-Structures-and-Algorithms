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

// BINARY TREE
// Creatiion
// Traversals- DFS(both iterative and recursive),BFS, Morris

// Structure of Binary Tree
typedef struct node
{
	char val;
	struct node *left;
	struct node *right;
} Node;

// Make a Binary Tree
node *BuildTree(node *root)
{
	cout << "Enter the data: ";
	char data;
	cin >> data;
	root->val = data;

	if (data == -1)
		return NULL;

	cout << "Enter data for inserting in left of " << data << endl;
	root->left = BuildTree(root->left);
	cout << "Enter data for inserting in right of " << data << endl;
	root->right = BuildTree(root->right);

	return root;
}

// Traversals
// Depth First Values
// Iterative
// Time Complexity- O(n)
stack<node *> values;
void DepthFirstValuesItr(node *root)
{
	values.push(root);
	while (!values.empty())
	{
		node *current = values.top();
		values.pop();
		cout << current->val << " ";
		// Output- a c f b e d
		if (current->left)
			values.push(current->left);
		if (current->right)
			values.push(current->right);
	}
}
// Recursive
// Time Complexity- O(n)
void DepthFirstValuesRec(node *root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";
	// Output- a c f b e d
	if (root->right)
		DepthFirstValuesRec(root->right);
	if (root->left)
		DepthFirstValuesRec(root->left);
}

// BFS
// Time Complexity- O(n)
void BreadthFirstValues(node *root)
{
	if (root == NULL)
		return;
	queue<node *> values;
	values.push(root);
	while (!values.empty())
	{
		node *current = values.front();
		values.pop();
		cout << current->val << " ";
		// Output- a b c d e f

		if (current->left)
			values.push(current->left);
		if (current->right)
			values.push(current->right);
	}
}

// Morris Traversal(inOrder)
// Time Complexity- O(n)
void MorrisTraversal(node *root)
{
	node *curr = root;
	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			cout << curr->val << " ";
			curr = curr->right;
		}
		else
		{
			node *prev = curr->left;
			while (prev->right and prev->right != curr)
			{
				prev = prev->right;
			}
			if (prev->right == NULL)
			{
				prev->right = curr;
				curr = curr->left;
			}
			else
			{
				prev->right = NULL;
				cout << curr->val << " ";
				curr = curr->right;
			}
		}
	}
}

void solve()
{
	// Write code here
	// Define nodes
	node *a = new Node();
	node *b = new Node();
	node *c = new Node();
	node *d = new Node();
	node *e = new Node();
	node *f = new Node();

	// Initialize nodes
	a->val = 'a';
	b->val = 'b';
	c->val = 'c';
	d->val = 'd';
	e->val = 'e';
	f->val = 'f';
	// Assigning relations
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	// Visual Representation
	//      a
	//     / \
    	//    b   c
	//   / \   \
    	//  d   e   f

	// Traversals
	// DFS(iterative)
	cout << "DFS(iterative)" << endl;
	DepthFirstValuesItr(a);
	cout << endl;

	// DFS(recursive)
	cout << "DFS(recursive)" << endl;
	DepthFirstValuesRec(a);
	cout << endl;

	// BFS
	cout << "BFS" << endl;
	BreadthFirstValues(a);
	cout << endl;

	cout << "Morris Traversal" << endl;
	MorrisTraversal(a);
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

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
