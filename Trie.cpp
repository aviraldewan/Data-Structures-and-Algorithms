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

// Trie

// NOTE- IT IS ASSUMED THAT ALL WORDS ARE IN CAPS
// Implementation
// Insertion
// Search
// Deletion

class TrieNode {
	public:
	char data;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode(char ch)
	{
		data = ch;
		rep(i,0,26)
			children[i] = NULL;
		isTerminal = false;
	}
};

class Trie {
	public:
	TrieNode* root;

	Trie() {
		root = new TrieNode('\0');
	}

	void insertUtil(TrieNode* root, string word)
	{
		// Base Case
		if (sz(word) == 0)
		{
			root->isTerminal = true;
			return;
		}

		int index = word[0] - 'A';
		TrieNode* child;

		// Word is Present in string
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			// Word is Absent
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		insertUtil(child, word.substr(1));
	}

	void insertWord(string word)
	{
		insertUtil(root,word);
	}

	bool searchUtil(TrieNode* root, string word)
	{
		// Base Case
		if (sz(word) == 0)
			return root->isTerminal;

		int index = word[0] - 'A';
		TrieNode* child;

		// Word is Present
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			// Word is Absent
			return false;
		}

		// Recursion
		return searchUtil(child, word.substr(1));
	}

	bool searchWord(string word)
	{
		return searchUtil(root,word);
	}

	// returns true if root node has no children, else false
	bool isEmpty(TrieNode* root)
	{
		rep(i,0,26)
			if (root->children[i])
				return false;

		return true;
	}

	// Recursive function to delete a key from give Trie
	TrieNode* remove(TrieNode* root, string key, int depth = 0)
	{
		// If tree is empty
		if (!root)
			return NULL;

		// If last character of key is being processed
		if (depth == sz(key))
		{
			// This node is no more end of word after
			// removal of given key
			if (root->isTerminal)
				root->isTerminal = false;

			// If given is not prefix of any other word
			if (isEmpty(root))
			{
				delete(root);
				root = NULL;
			}

			return root;
		}

		// If not last character, recur for the child
		// obtained using ASCII value
		int index = key[depth] - 'A';
		root->children[index] =
			remove(root->children[index],key,depth+1);

		// If root doesnot have any child(its only child got
		// deleted), and it is not end of another word
		if (isEmpty(root) and root->isTerminal == false)
		{
			delete(root);
			root = NULL;
		}

		return root;
	}

	void TrieDelete(string word)
	{
		remove(root,word);
	}
};

void solve()
{
	// Write code here

	// Create new Trie
	Trie *t = new Trie();

	// Insert new word in Trie
	t->insertWord("ABCD");
	t->insertWord("HI");

	// Search a word in Trie
		// Answer is Yes
	cout << "Present or Not: " << t->searchWord("ABCD") << endl;
		// Answer is No
	cout << "Present or Not: " << t->searchWord("ABCDW") << endl;

	t->TrieDelete("ABCD");
	// Answer is No
	cout << "Present or Not: " << t->searchWord("ABCD") << endl;
	// Answer is Yes
	cout << "Present or Not: " << t->searchWord("HI") << endl;
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
