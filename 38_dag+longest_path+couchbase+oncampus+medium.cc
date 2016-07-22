// http://stackoverflow.com/questions/2525316/longest-acyclic-path-in-a-directed-unweighted-graph

// Given a acylic directed graph, find the length of longest path from root to any leaf.
// 
// SOLUTION:
// Idea here is simple, DFS and save the state, so that following type of graph 
// does not end up doing repeated computations.
// /\
// \/
// /\
// \/
//
// If we simply do the DFS, then complexity would be exponential.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct Node {
	int val;
	std::vector<Node*> children;
	
	Node (int v) {
		val = v;
	}

	void addChild(Node* n) {
		children.push_back(n);
	}
};

int findLongestPath(Node *node, std::unordered_map<Node*, int>* sol) {
	int max = 0;
	if (sol->find(node) != sol->end()) {
		return (*sol)[node];
	}

	for (auto child : node->children) {
		int temp = findLongestPath(child, sol);
		if (temp > max) {
			max = temp;
		}
	}
	(*sol)[node] = max + 1;
	return max + 1;
}

int main() {
	Node *root = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);

	root->addChild(n2);
	root->addChild(n3);

	n2->addChild(n3);
	n3->addChild(n4);

	std::unordered_map<Node*, int> sol; 
	cout << findLongestPath(root, &sol) << endl;
}
