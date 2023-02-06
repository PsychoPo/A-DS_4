#include <iostream>
#include <fstream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree<int> obj;
	int answer;
	int val;
	int size;
	int *arr;
	string fileName;
	ofstream fout;
	ifstream fin;
	vector<int> Palindroms;
	do
	{
		cout << "1. Writing a tree from an array" << endl;
		cout << "2. Insert Node" << endl;
		cout << "3. Search Node" << endl;
		cout << "4. Delete Node" << endl;
		cout << "5. Print BinaryTree values and TRAVERSE" << endl;
		cout << "6. Input Tree from FILE" << endl;
		cout << "7. Output Tree in FILE" << endl;
		cout << "8. Palindroms and NODE level" << endl;
		cout << "0. Exit Program" << endl;

		cin >> answer;

		TreeNode<int> *new_node = new TreeNode<int>();

		switch (answer)
		{
		case 0:
			break;
		case 1:
			cout << "Enter size of the array: ";
			cin >> size;
			arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				cout << i << " element = ";
				cin >> arr[i];
			}
			cout << "\n";
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n\n";
			for (int i = 0; i < size; i++)
			{
				obj.addFarray(arr[i]);
			}
			delete arr;
			break;
		case 2:
			cout << "INSERT" << endl;
			cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
			cin >> val;
			new_node->value = val;
			obj.root = obj.insertRecursive(obj.root, new_node);
			cout << endl;
			break;
		case 3:
			cout << "SEARCH" << endl;
			cout << "Enter VALUE of TREE NODE to Search in BST: ";
			cin >> val;
			new_node = obj.iterativeSearch(val);
			if (new_node != nullptr)
				cout << "\nValue found\n\n";
			else
				cout << "\nValue NOT found!\n\n";
			break;
		case 4:
			cout << "DELETE" << endl;
			cout << "Enter VALUE of TREE NODE to Delete in BST: ";
			cin >> val;
			new_node = obj.iterativeSearch(val);
			if (new_node != nullptr)
			{
				obj.deleteNode(obj.root, val);
				cout << "\nValue DELETED\n\n";
			}
			else
			{
				cout << "\nValue NOT found!\n\n";
			}
			break;
		case 5:
			cout << "PRINT AND TRAVERSE" << endl;
			obj.print2D(obj.root, 5);
			cout << "Preorder Traversal:\n";
			obj.printPreorder(obj.root);
			cout << endl;
			cout << "Inorder Traversal:\n";
			obj.printInorder(obj.root);
			cout << endl;
			cout << "Postorder Traversal:\n";
			obj.printPostorder(obj.root);
			cout << "\n\n";
			break;
		case 6:
			cout << "Enter file name: ";
			cin >> fileName;
			fin.open(fileName);
			if (fin.is_open())
			{
				fin >> size;
				arr = new int[size];
				cout << "\n";
				for (int i = 0; i < size; i++)
				{
					fin >> arr[i];
					cout << arr[i] << " ";
				}
				for (int i = 0; i < size; i++)
				{
					obj.addFarray(arr[i]);
				}
				cout << "\n\n";
				delete arr;
			}
			else
			{
				cout << "\nERROR! FILE isn't open!\n\n";
			}
			fin.close();
			break;
		case 7:
			cout << "Enter file name: ";
			cin >> fileName;
			fout.open(fileName);
			obj.print2DFile(obj.root, 5, fout);
			cout << "\nThe file is filled in successfully\n\n";
			fout.close();
			break;
		case 8:
			obj.getReverseNode(obj.root, Palindroms);
			for (int i = 0; i < Palindroms.size(); i++)
			{
				cout << Palindroms[i] << " ";
			}
			cout << "\n\n";
			for (int i = 0; i < Palindroms.size(); i++)
			{
				cout << Palindroms[i] << ": Level - " << obj.getLevel(obj.root, Palindroms[i]) << "\n";
			}
			cout << "\n\n";
			break;
		default:
			cout << "Enter correct number " << endl;
		}
	} while (answer != 0);

	return 0;
}