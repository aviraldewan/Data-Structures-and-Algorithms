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

// Binary Search Tree

// Creation
// Traversals- DFS(recursive), BFS
// Deletion
// Min/Max Values
// Searching given number

// Structure of Binary Search Tree;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Node;

// Traversals
// DFS(recursive)
void DFS(Node *root)
{
	if (root == NULL)
	{
		// cout << endl;
		return;
	}

	cout << root->data << " ";

	if (root->left)
	{
		DFS(root->left);
	}
	if (root->right)
	{
		DFS(root->right);
	}
}

// BFS
void BFS(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();

		if (cur == NULL)
		{
			cout << endl;
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << cur->data << " ";
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
}

// Inserting data in BST
Node *insertIntoBST(Node *root, int data)
{
	// Base Case
	if (root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (data > root->data)
		root->right = insertIntoBST(root->right, data);
	else
		root->left = insertIntoBST(root->left, data);

	return root;
}

// Main function to take input for BST
void takeInput(Node *&root)
{
	int data;
	cin >> data;

	while (data != -1)
	{
		insertIntoBST(root, data);
		cin >> data;
	}
}

// Find minimum value in BST
Node *minVal(Node *root)
{
	Node *temp = root;
	while (temp and temp->left != NULL)
		temp = temp->left;

	return temp;
}

// Find maximum value in BST
Node *maxVal(Node *root)
{
	Node *temp = root;
	while (temp and temp->right != NULL)
		temp = temp->right;

	return temp;
}

// Check whether given number, x, is present in BST or not
string FindX(Node *root, string s, int x)
{
	if (root == NULL)
		return s;

	Node *temp = root;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			s = "Yes";
			return s;
		}
		if (x < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}

	return s;
}

// Delete the node having given value from BST
Node *deleteFromBST(Node *root, int val)
{
	// Base Case
	if (root == NULL)
		return root;

	if (root->data == val)
	{
		// 0 child
		if (root->left == NULL and root->right == NULL)
		{
			delete root;
			return NULL;
		}
		// 1 child
		// left child
		if (root->left != NULL and root->right == NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		// right child
		if (root->left == NULL and root->right != NULL)
		{
			Node *temp = root->right;
			delete root;
			return temp;
		}
		// 2 child
		if (root->left != NULL and root->right != NULL)
		{
			Node* temp = minVal(root->right);
			root->data = temp->data;
			root->right = deleteFromBST(root->right, temp->data);
			return root;
		}
	}

	if (root->data > val)
	{
		root = deleteFromBST(root->left, val);
		return root;
	}
	else
	{
		root = deleteFromBST(root->right, val);
		return root;
	}
}

void solve()
{
	// Write code here
	cout << "Enter value of root" << endl;
	int data;
	cin >> data;

	Node *root = new Node();
	root->data = data;
	root->left = NULL;
	root->right = NULL;

	cout << "Enter data to create Binary Search Tree" << endl;
	takeInput(root);

	// BFS in BST
	cout << "BFS" << endl;
	BFS(root);
	// DFS in BST
	cout << "DFS" << endl;
	DFS(root);
	cout << endl;

	// Finding Minimum value in BST
	cout << "Minimum value in BST: " << minVal(root)->data << endl;
	// Finding Maximum value in BST
	cout << "Maximum value in BST: " << maxVal(root)->data << endl;

	// Checking whether entered value is in BST or not
	cout << "Enter number to find in BST: ";
	int x;
	cin >> x;
	string s = "No";
	cout << "Is " << x << " present in BST or not: " << FindX(root, s, x) << endl;

	// Deleting a node from BST
	cout << "Enter number to delete from BST: ";
	int del;
	cin >> del;
	Node* temp = deleteFromBST(root, del);
	cout << del << " is Deleted from BST\n";
	cout << "BFS after deletion of " << del << " from BST" << endl;
	BFS(root);
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
