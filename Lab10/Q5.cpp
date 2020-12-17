
#include <iostream>
using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
};

class BT
{
private:
	node* root;
public:
	BT()
	{
		root = NULL;
	}
	void insert(node* node, int value);
	node* getRoot();

	bool isHeapUtil(struct node* root1);
	bool isCompleteUtil(struct node* root1, unsigned int index1, unsigned int number_nodes);
	unsigned int countNodes(struct node* root1);
	bool isHeap(struct node* root1);
};
node* BT::getRoot()
{
	return this->root;
}

void BT::insert(node* leaf, int value)
{
	if (root == NULL)
	{
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;

	}
	else
	{
		if (value < leaf->data)
		{
			if (leaf->left != NULL)
			{
				insert(leaf->left, value);
			}
			else
			{
				leaf->left = new node;
				leaf->left->data = value;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
		}
		else if (value >= leaf->data)
		{
			if (leaf->right != NULL)
			{
				insert(leaf->right, value);
			}
			else
			{
				leaf->right = new node;
				leaf->right->data = value;
				leaf->right->right = NULL;
				leaf->right->left = NULL;
			}
		}
	}
}

unsigned int BT::countNodes(struct node* root1) 
{
	if (root1 == NULL)
		return (0);
	return (1 + countNodes(root1->left) + countNodes(root1->right));
}

bool BT::isCompleteUtil(struct node* root1, unsigned int index1, unsigned int number_nodes) 
{
	if (root1 == NULL)
		return (true);
	if (index1 >= number_nodes)
		return (false);
	// Recur for left and right subtrees
	return (isCompleteUtil(root1->left, 2 * index1 + 1, number_nodes) && isCompleteUtil(root1->right, 2 * index1 + 2, number_nodes));
}
bool BT::isHeapUtil(node* root1) 
{
	if (root1->left == NULL && root1->right == NULL)
		return (true);
	if (root1->right == NULL) {
		return (root1->data = root1->left->data);
	}
	else {
		if (root1->data >= root1->left->data &&
			root1->data >= root1->right->data)
			return ((isHeapUtil(root1->left)) &&
				(isHeapUtil(root1->right)));
		else
			return (false);
	}
}
bool BT::isHeap(struct node* root1)
{
	unsigned int node_count = countNodes(root1);
	unsigned int index1 = 0;
	if (isCompleteUtil(root1, index1, node_count) &&
		isHeapUtil(root1))
		return true;
	return false;
}


int main()
{
	BT* tree = new BT();
	int value, choice;
	while (1)
	{
	A:cout << "\n\n\t1. Insert\n"
		"\t2. Check if Tree is Heap\n"
		"\t0. Exit\n"
		"\tChoice: ";
	cin >> choice;
	if (choice == 0)
	{
		exit(0);
	}
	if (choice == 1)
	{
		cout << "Enter Number: ";
		cin >> value;
		system("cls");
		tree->insert(tree->getRoot(), value);
	}
	else if (choice == 2)
	{
		if (tree->isHeap(tree->getRoot()))
			cout << "Given binary tree is a Heap\n";
		else
			cout << "Given binary tree is not a Heap\n";
	}
	else
	{
		cout << "Invaid Choice!!\n";
		goto A;
	}

	}
}

