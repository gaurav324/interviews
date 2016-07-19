// Determine if a linkedlist is a palindrome or not.
//
// THINGS LEARNT:
// 1) Link list has slow pointers and fast pointers approach, which is quite cool.
// 2) Idea here was to reverse the half linked list and then go in both directions.
//    Here again we have two choices: Reverse the first part or reverse the later part.
//    That does not matter. Thing that actually matters is after reversing, where we 
//    do start the matching from, inside out or out to in. If we come from in to out, 
//    we have to take care of even/odd case. If we come from out to in, both pointers
//    either merge at odd length center or both become null (even case).
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
	
	// Reverse the later part.
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
