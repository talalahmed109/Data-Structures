//#include <iostream>
//using namespace std;
//
//struct node
//{
//	int data;
//	node* left;
//	node* right;
//};
//
//class BST
//{
//private:
//	node* root;
//public:
//	BST()
//	{
//		root = NULL;
//	}
//	void insert(node* node, int value);
//
//	int height(node* temp);
//	int diff(node* temp);
//	node* rr_rotation(node* parent);
//	node* ll_rotation(node* parent);
//	node* lr_rotation(node* parent);
//	node* rl_rotation(node* parent);
//	node* balance(node* temp);
//
//	void inorder(node* leaf);
//	void postorder(node* leaf);
//	void preorder(node* leaf);
//	
//	node* getRoot();
//};
//node* BST::getRoot()
//{
//	return this->root;
//}
//
//void BST::insert(node* leaf, int value)
//{
//	if (root == NULL)
//	{
//		root = new node;
//		root->data = value;
//		root->left = NULL;
//		root->right = NULL;
//
//	}
//	else
//	{
//		if (value < leaf->data)
//		{
//			if (leaf->left != NULL)
//			{
//				insert(leaf->left, value);
//			}
//			else
//			{
//				leaf->left = new node;
//				leaf->left->data = value;
//				leaf->left->left = NULL;
//				leaf->left->right = NULL;
//			}
//		}
//		else if (value >= leaf->data)
//		{
//			if (leaf->right != NULL)
//			{
//				insert(leaf->right, value);
//			}
//			else
//			{
//				leaf->right = new node;
//				leaf->right->data = value;
//				leaf->right->right = NULL;
//				leaf->right->left = NULL;
//			}
//		}
//	}
//}
//
//
//
//int BST::height(node* temp)
//{
//	int h = 0;
//	if (temp != NULL)
//	{
//		int l_height = height(temp->left);
//		int r_height = height(temp->right);
//		int max_height = max(l_height, r_height);
//		h = max_height + 1;
//	}
//	return h;
//}
//
//
//int BST::diff(node* temp)
//{
//	int l_height = height(temp->left);
//	int r_height = height(temp->right);
//	int b_factor = l_height - r_height;
//	return b_factor;
//}
//
//node* BST::rr_rotation(node* parent)
//{
//	node* temp;
//	temp = parent->right;
//	parent->right = temp->left;
//	temp->left = parent;
//	return temp;
//}
///*
// * Left- Left Rotation
// */
//
//node* BST::ll_rotation(node* parent)
//{
//	node* temp;
//	temp = parent->left;
//	parent->left = temp->right;
//	temp->right = parent;
//	return temp;
//}
//
//node* BST::lr_rotation(node* parent)
//{
//	node* temp;
//	temp = parent->left;
//	parent->left = rr_rotation(temp);
//	return ll_rotation(parent);
//}
//
//
//
//node* BST::rl_rotation(node* parent)
//{
//	node* temp;
//	temp = parent->right;
//	parent->right = ll_rotation(temp);
//	return rr_rotation(parent);
//}
//
//
//
//node* BST::balance(node* temp)
//{
//	int bal_factor = diff(temp);
//	if (bal_factor > 1)
//	{
//		if (diff(temp->left) > 0)
//			temp = ll_rotation(temp);
//		else
//			temp = lr_rotation(temp);
//	}
//	else if (bal_factor < -1)
//	{
//		if (diff(temp->right) > 0)
//			temp = rl_rotation(temp);
//		else
//			temp = rr_rotation(temp);
//	}
//	return temp;
//}
//
//void BST::inorder(node* leaf)
//{
//	if (leaf != NULL)
//	{
//		inorder(leaf->left);
//		cout << leaf->data << " ";
//		inorder(leaf->right);
//	}
//}
//
//void BST::preorder(node* leaf)
//{
//	if (leaf != NULL)
//	{
//		cout << leaf->data << ",";
//		preorder(leaf->left);
//		preorder(leaf->right);
//	}
//}
//
//void BST::postorder(node* leaf)
//{
//	if (leaf != NULL)
//	{
//		postorder(leaf->left);
//		postorder(leaf->right);
//		cout << leaf->data << " ";
//	}
//}
//
//int main()
//{
//	BST* tree = new BST();
//	int value, choice;
//	while (1)
//	{
//	A:cout << "\n\n\t1. Insert\n"
//		"\t2. Convert to AVL\n"
//		"\t3. Display\n"
//		"\t0. Exit\n"
//		"\tChoice: ";
//	cin >> choice;
//	if (choice == 0)
//	{
//		exit(0);
//	}
//	if (choice == 1)
//	{
//		cout << "Enter Number: ";
//		cin >> value;
//		system("cls");
//		tree->insert(tree->getRoot(), value);
//	}
//	else if (choice == 2)
//	{
//		int opt;
//		cout << "\n\n\tSelect Rotation to Perform:\n "
//			"\t1. Left Left Rotation\n"
//			"\t2. Right Right Rotation\n"
//			"\t3. Left Right Rotation\n"
//			"\t4. Right Left Rotation\n"
//			"\tChoice: ";
//		cin >> opt;
//		if (opt == 1)
//		{
//			tree->ll_rotation(tree->getRoot());
//			cout << "\tConverted to AVL\n";
//		}
//		if (opt == 2)
//		{
//			tree->rr_rotation(tree->getRoot());
//			cout << "\tConverted to AVL\n";
//		}
//		if (opt == 3)
//		{
//			tree->lr_rotation(tree->getRoot());
//			cout << "\tConverted to AVL\n";
//		}
//		if (opt == 4)
//		{
//			tree->rl_rotation(tree->getRoot());
//			cout << "\tConverted to AVL\n";
//		}
//	}
//	else if (choice == 3)
//	{
//		int opt;
//		system("cls");
//	B:cout << "\n\t1. Inorder\n"
//		"\t2. Pre Order\n"
//		"\t3. Post Order\n"
//		"\t4. Go Back\n"
//		"\tChoice: ";
//	cin >> opt;
//	if (opt == 1)
//	{
//		tree->inorder(tree->getRoot());
//		goto B;
//	}
//	else if (opt == 2)
//	{
//		tree->preorder(tree->getRoot());
//		goto B;
//	}
//	else if (opt == 3)
//	{
//		tree->postorder(tree->getRoot());
//		goto B;
//	}
//	else if (opt == 4)
//	{
//		goto A;
//	}
//	else
//	{
//		cout << "Invaid Choice!!\n";
//		goto B;
//	}
//	}
//	else
//	{
//		cout << "Invaid Choice!!\n";
//		goto A;
//	}
//	}
//}
