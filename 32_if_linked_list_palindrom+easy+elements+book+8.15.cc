// Determine if a linkedlist is a palindrome or not.
//
#include <iostream>

using namespace std;
struct Node {
	char val;
	Node* next;
	Node(char val) {this->val = val; this->next = NULL;}
};

bool isLinkedListPalindrome(Node* root) {
	if (root == NULL || root->next == NULL) {
		return true;
	}

	Node *slow = root;
	Node *fast = root;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	// Reverse the latter part.
	Node *next = NULL;
	Node *prev = NULL;
	while(slow != NULL) {
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}

	// Check for palindrome.
	Node *left = root;
	Node *right = prev;
	while(right != NULL) {
		if (left->val != right->val) {
			return false;
		}
		left = left->next;
		right = right->next;
	}
	return true;
}

int main() {
	Node *root1 = new Node('g');
	root1->next = new Node('a');
	root1->next->next = new Node('u');
	root1->next->next->next = new Node('a');
	root1->next->next->next->next = new Node('g');
	cout << isLinkedListPalindrome(root1) << endl;

	Node *root2 = new Node('g');
	root2->next = new Node('a');
	root2->next->next = new Node('u');
	cout << isLinkedListPalindrome(root2) << endl;
}
