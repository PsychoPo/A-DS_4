#pragma once
#include <iostream>
#include <vector>
#define SPACE 10
using namespace std;

template <class Data>
class TreeNode
{
public:
	Data value; // data(key)
	TreeNode *left;
	TreeNode *right;

	TreeNode()
	{
		value = 0;
		left = nullptr;
		right = nullptr;
	}
	TreeNode(Data v)
	{
		value = v;
		left = nullptr;
		right = nullptr;
	}
	~TreeNode() {}
};

template <class Type>
class BinaryTree
{
public:
	TreeNode<Type> *root;

	BinaryTree()
	{
		root = nullptr;
	}
	bool isTreeEmpty() // check if empty
	{
		if (root == nullptr)
			return true;
		else
			return false;
	}
	void add(TreeNode<Type> *&t, int n)
	{ // add node
		if (t == NULL)
		{
			t = new TreeNode<Type>(n);
		}
		else
		{
			if (n < t->value)
			{
				add(t->left, n);
			}
			else
			{
				add(t->right, n);
			}
		}
	}
	void addFarray(int n)
	{ // add from array
		add(root, n);
	}
	TreeNode<Type> *insertRecursive(TreeNode<Type> *r, TreeNode<Type> *new_node)
	{
		if (r == nullptr)
		{
			r = new_node;
			return r;
		}
		if (new_node->value < r->value)
		{
			r->left = insertRecursive(r->left, new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insertRecursive(r->right, new_node);
		}
		else
		{
			cout << "No duplicate values allowed!\n";
			return r;
		}
		return r;
	}
	void print2D(TreeNode<Type> *r, int space) // Print tree
	{
		if (r == nullptr)
			return;
		space += SPACE;
		print2D(r->right, space);
		cout << endl;
		for (int i = SPACE; i < space; i++)
			cout << " ";
		cout << r->value << "\n";
		print2D(r->left, space);
	}
	void print2DFile(TreeNode<Type> *r, int space, ofstream &fout) // print in FILE
	{
		if (r == nullptr)
			return;
		space += SPACE;
		print2DFile(r->right, space, fout);
		fout << endl;
		for (int i = SPACE; i < space; i++)
			fout << " ";
		fout << r->value << "\n";
		print2DFile(r->left, space, fout);
	}
	void printPreorder(TreeNode<Type> *r) // Root, Left, Right
	{
		int count = 0;
		if (r == nullptr)
			return;
		cout << r->value << " ";
		printPreorder(r->left);
		printPreorder(r->right);
	}
	void printInorder(TreeNode<Type> *r) // Left, Root, Right
	{
		if (r == nullptr)
			return;
		printInorder(r->left);
		cout << r->value << " ";
		printInorder(r->right);
	}
	void printPostorder(TreeNode<Type> *r) // Left, Right, Root
	{
		if (r == nullptr)
			return;
		printPostorder(r->left);
		printPostorder(r->right);
		cout << r->value << " ";
	}
	TreeNode<Type> *iterativeSearch(Type val) // search
	{
		if (root == nullptr)
		{
			return root;
		}
		else
		{
			TreeNode<Type> *temp = root;
			while (temp != nullptr)
			{
				if (val == temp->value)
				{
					return temp;
				}
				else if (val < temp->value)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}
			return nullptr;
		}
	}
	TreeNode<Type> *minValueNode(TreeNode<Type> *node) // min node
	{
		TreeNode<Type> *current = node;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	TreeNode<Type> *deleteNode(TreeNode<Type> *r, Type val) // delete node
	{
		if (r == nullptr)
		{
			return nullptr;
		}
		else if (val < r->value)
		{
			r->left = deleteNode(r->left, val);
		}
		else if (val > r->value)
		{
			r->right = deleteNode(r->right, val);
		}
		else
		{
			if (r->left == nullptr)
			{
				TreeNode<Type> *temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == nullptr)
			{
				TreeNode<Type> *temp = r->left;
				delete r;
				return temp;
			}
			else
			{
				TreeNode<Type> *temp = minValueNode(r->right);
				r->value = temp->value;
				r->right = deleteNode(r->right, temp->value);
			}
		}
		return r;
	}
	Type getLevelUtil(TreeNode<Type> *r, Type value, int level)
	{
		if (r == nullptr)
			return 1;
		if (r->value == value)
			return level;

		int downlevel = getLevelUtil(r->left, value, level + 1);
		if (downlevel != 0)
			return downlevel;
		downlevel = getLevelUtil(r->right, value, level + 1);
		return downlevel;
	}
	Type getLevel(TreeNode<Type> *r, Type value) // nodes levels
	{
		return getLevelUtil(r, value, 0);
	}
	void getReverseNode(TreeNode<Type> *r, vector<int> &arr) // get Palindroms
	{
		if (r == nullptr)
			return;
		Type n = r->value;
		Type tmp = n;
		Type a = n % 10;
		while (tmp /= 10)
		{
			a = a * 10 + tmp % 10;
		}
		if (a == n)
		{
			arr.push_back(n);
		}
		getReverseNode(r->left, arr);
		getReverseNode(r->right, arr);
	}

	~BinaryTree() {}
};