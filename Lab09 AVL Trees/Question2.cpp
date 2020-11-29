//
//#include<iostream>
//using namespace std;
//
//struct node
//{
//    int data, height;
//    node* left;
//    node* right;
//}*root;
//class AVL
//{
//
//private:
//    node* root;
//public:
//    AVL()
//    {
//        root = NULL;
//    }
//
//    int height(node* t)
//    {
//        return (t == NULL ? -1 : t->height);
//    }
//
//    node* insert(node* Node, int value)
//    {
//        if (Node == NULL)
//        {
//            Node = new node;
//            Node->data = value;
//            Node->height = 0;
//            Node->left = Node->right = NULL;
//        }
//        else if (value < Node->data)
//        {
//            if (Node->left != NULL)
//            {
//                insert(Node->left, value);
//            }
//            else
//            {
//                Node->left = new node();
//                Node->left->data = value;
//                Node->left->left = NULL;
//                Node->left->right = NULL;
//                if (height(Node->left) - height(Node->right) == 2)
//                {
//                    if (value < Node->left->data)
//                        Node = rr_rotation(Node);
//                    else
//                        Node = rl_rotation(Node);
//                }
//            }
//        }
//        else if (value >= Node->data)
//        {
//            if (Node->right != NULL)
//            {
//                insert(Node->right, value);
//            }
//            else
//            {
//                Node->right = new node();
//                Node->right->data = value;
//                Node->right->right = NULL;
//                Node->right->left = NULL;
//                if (height(Node->right) - height(Node->left) == 2)
//                {
//                    if (value > Node->right->data)
//                        Node = ll_rotation(Node);
//                    else
//                        Node = lr_rotation(Node);
//                }
//            }
//        }
//        Node->height = max(height(Node->left), height(Node->right)) + 1;
//        return Node;
//    }
//    node* rr_rotation(node* Node)
//    {
//        node* temp;
//        temp = Node->right;
//        Node->right = temp->left;
//        temp->left = Node;
//        return temp;
//    }
//    node* ll_rotation(node* Node)
//    {
//        node* temp;
//        temp = Node->left;
//        Node->left = temp->right;
//        temp->right = Node;
//        return temp;
//    }
//    node* lr_rotation(node* Node)
//    {
//        node* temp;
//        temp = Node->left;
//        Node->left = rr_rotation(temp);
//        return ll_rotation(Node);
//
//    }
//    node* rl_rotation(node* Node)
//    {
//        node* temp;
//        temp = Node->right;
//        Node->right = ll_rotation(temp);
//        return rr_rotation(Node);
//
//    }
//
//    bool checkAVL(node* root) 
//    {
//        int lh;
//        int rh;
//        if (root == NULL)
//            return 1;
//        lh = height(root->left); 
//        rh = height(root->right); 
//        if (abs(lh - rh) <= 1 && checkAVL(root->left) && checkAVL(root->right))
//            return 1;
//        return 0;
//    }
//
//};
//
//int main()
//{
//    AVL A;
//    int value, choice;
//    while (1)
//    {
//    A:cout << "1. Insert\n"
//        "2. Check if Tree is AVl or Not\n"
//        "Choice: ";
//    cin >> choice;
//    if (choice == 1)
//    {
//        cout << "Enter Value: ";
//        cin >> value;
//        root = A.insert(root, value);
//    }
//    if (choice == 2)
//    {
//        if (A.checkAVL(root))
//            cout << "The Tree is AVL Tree" << endl;
//        else
//            cout << "The Tree is not AVL Tree " << endl;
//    }
//    }
//}
//
