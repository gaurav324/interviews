// Goal of this exercise is to code up all the traversal algorithms and that too recursive and iterative versions.
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int v;
	Node* left;
	Node* right;

	Node(int v) : v(v), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
	Node* root;
	BinaryTree() {root = NULL;}

	void Insert(int v) {
		if (root == NULL) {
			root = new Node(v);
			return;
		}
		
		InsertHelper(root, v);
	}
	
	void InOrderTraversalRecursive() {
		InOrderTraversalHelper(root);
		cout << "\n";
  }

	void InOrderTraversalIterative() {
    vector<pair<Node*, bool>> stack;
		stack.push_back({root, false});
	
		while(!stack.empty()) {
			auto& ele = stack.back();
			if (ele.first == NULL) {
				stack.pop_back();
				continue;
			}

			if (!ele.second) {
				ele.second = true;
				stack.push_back({ele.first->left, false});
			} else {
				stack.pop_back();
				cout << ele.first->v << "\t";
				stack.push_back({ele.first->right, false});
			}
		}	
	
		cout << endl;
	}

	void InOrderTraversalIterativeBetter() {
		Node* node = root;
		vector<Node*> stack;
		while(node != NULL || !stack.empty()) {
			if (node != NULL) {
				stack.push_back(node);
				node = node->left;
			} else {	
			  node = stack.back();
				stack.pop_back();
				cout << node->v << "\t";
				node = node->right;
			}
		}
	}

	void PostOrderTraversalIterative() {
		Node* node = root;
		vector<Node*> stack;
		while(node != NULL || !stack.empty()) {
			if (node != NULL) {
				stack.push_back(node);
				node = node->left;
			} else {
			}
		}
	}

	void PreOrderTraversalRecursive() {
		PreOrderTraversalHelper(root);
		cout << "\n";
  }

	void PostOrderTraversalRecursive() {
		PostOrderTraversalHelper(root);
		cout << "\n";
  }

private:
	void InsertHelper(Node* root, int v) {
		if(v < root->v) {
			if (root->left) {
				InsertHelper(root->left, v);
			} else {
				root->left = new Node(v);
			}
		} else {
			if (root->right) {
				InsertHelper(root->right, v);
			} else {
				root->right = new Node(v);
			}
		}
		return;
	}

	void InOrderTraversalHelper(Node* root) {
		if (root == NULL) {
			return;
		}
	 	InOrderTraversalHelper(root->left);
		cout << root->v << "\t";
		InOrderTraversalHelper(root->right);
	}

	void PreOrderTraversalHelper(Node* root) {
		if (root == NULL) {
			return;
		}
		cout << root->v << "\t";
	 	PreOrderTraversalHelper(root->left);
		PreOrderTraversalHelper(root->right);
	}

	void PostOrderTraversalHelper(Node* root) {
		if (root == NULL) {
			return;
		}
	 	PostOrderTraversalHelper(root->left);
		PostOrderTraversalHelper(root->right);
		cout << root->v << "\t";
	}
};

int main() {
	BinaryTree tree;
	tree.Insert(50);
	tree.Insert(25);
	tree.Insert(75);
	tree.Insert(10);
	tree.Insert(40);
	tree.Insert(60);
	
	cout << "In-order traversal" << endl;
	tree.InOrderTraversalRecursive();

	cout << "Pre-order traversal" << endl;
	tree.PreOrderTraversalRecursive();

	cout << "Post-order traversal" << endl;
	tree.PostOrderTraversalRecursive();

	cout << "In-order traversal Iterative" << endl;
	tree.InOrderTraversalIterative();
	
	cout << "In-order traversal Iterative better" << endl;
	tree.InOrderTraversalIterativeBetter();
}
