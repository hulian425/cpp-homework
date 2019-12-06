#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// An AVL tree node
class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};


int max(int a, int b)
{
	return a > b ? a : b;
}

int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

Node* rightRotation(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));
	return  x;
}
Node* leftRotation(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));
	return y;
}

int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);

}
int gerBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else return node;

	node->height = 1 + max(height(node->left), height(node->right));
	int balance = (getBalance(node));
	if (balance > 1 && key < node->left->key)
		return rightRotation(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	if (balance < -1 && key > node->right->key)
		return leftRotation(node);
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}

	return node;
}

Node* minValueNode(Node* node)
{
	Node* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}



Node* deleteNode(Node* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			Node* temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);

		}
	}

	if (root == NULL)
		return root;
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotation(root);
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotation(root);
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

void preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node* root = NULL;
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	cout << "Preorder traversal of the "
		"constructed AVL tree is \n";
	preOrder(root);

	root = deleteNode(root, 10);

	cout << "\nPreorder traversal after"
		<< " deletion of 10 \n";
	preOrder(root);

	return 0;
}
