/*
	Exercise:
	1. Build bsinary search tree
	2. Insert value into the bst
	3. Search element from bst
	4. Delete an element from bst
	5. Any optimization possible?
*/
#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* GetNode(int data) {
	TreeNode* newNode = new TreeNode();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;
	
	return newNode;
}

struct BST {
	TreeNode* root;
	BST() : root(nullptr) {}
	TreeNode* GetRoot() {
		return root;
	}
	void build(int array[], int size) {
		if (size == 0)
			return;
		// Add rest all the elements as child to this root
		for (int i = 0; i < size; ++i) {
			addNode(array[i]);
		}
	}
	// incase if user wants this api call - and this will be your conscious decision
	void addNode(int data) {
		TreeNode* np = GetNode(data);
		if (root == nullptr) {
			root = np;
			return;
		}
		else {
			insertChild(root, data);
		}
	}
	// So important method rewuired here is to add one method which will print the 
	// tree in some order, like in-order, pre-order, post-order
	// in-order traversal of bst will always produce increasing sorted data list 
	void inOrder(TreeNode* root) {
		if (!root)
			return;
		else {
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
	}
private:
	// This is the first method which is used to create the root here
	/*
		In BST data structure, there are always nodes are in order
		So, logical steps required here is

		1. BST is a hierarchical data structure
		2. BST, in most case holding the unique data among all the nodes,
		3. Everynode fall leftside of this node will be smaller in value and 
		   every node falling rightside is bigger than this node
		
		So now let's discuss where you will insert new child

	*/
	TreeNode* insertChild(TreeNode* parent, int data) {
		if (parent == nullptr) {
			return GetNode(data);
		}
		else
		{
			if (data < parent->data) {
				parent->left = insertChild(parent->left, data);
			}
			else
				parent->right = insertChild(parent->right, data);
		}
		return parent;
	}

};

// driver code
int main() {
	BST bst;
	int array[] = {6,4,8,2,5};
	bst.build(array, 5);
	bst.inOrder(bst.GetRoot());

	return 0;
}

#endif // FORREF

