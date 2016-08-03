/**
 * This one was a really good question. Tested me on graphs and topological sort.
 * I managed to do a decent job here. However, could not spot the topological order.
 * 
 * Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.
 * Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
   Output: Order of characters is 'b', 'd', 'a', 'c'
   Note that words are sorted and in the given language "baa" 
   comes before "abcd", therefore 'b' is before 'a' in output.
   Similarly we can find other orders.

   Input:  words[] = {"caa", "aaa", "aab"}
   Output: Order of characters is 'c', 'a', 'b'
 */

// SOLUTION: Things to notice about topological sort is that, whenever we see an element we just put it in a stack.
//           ****** KEY : We put numbers in stack, after all its children have been put onto the stack. ******
//           This just ensures that all of parents of a number would be added to stack later than me.
//           If there are two paths to a number, e.g:
//					 1--> 2 --> 3 and 1 --> 3.
//           If we reach 3 from 1, we first add 3. Then, 1 we come from second path, 2 also tries to add 3, and only
//           after it makes sure 3 is there, 2 is added later.
#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:	
	int V;
	vector<int> *adj;
public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V];
	}

	void AddEdge(int source, int dest) {
		adj[source].push_back(dest);
	}

	void TopologicalSortHelper(int i, std::vector<bool>& visited, std::vector<int>& stack) {
		visited[i] = true;
		
		vector<int>& ad = adj[i];
		for (int i=0; i < ad.size(); ++i) {
			if (!visited[ad[i]]) {
				TopologicalSortHelper(ad[i], visited, stack);
			}		
		}
		
		stack.push_back(i);
	}

	// Prints a topological sort of the entire graph.
	void TopologicalSort() {
		vector<bool> visited;
		visited.resize(V, false);

		vector<int> stack;
		for (int i=0; i < V; ++i) {
			if (!visited[i]) {
				TopologicalSortHelper(i, visited, stack);
			}
		}		

		while(!stack.empty()) {
			cout << stack.back() << endl;
			stack.pop_back();
		}
	}
};

int main() {
	Graph g(5);
	g.AddEdge(0, 1);
	g.AddEdge(4, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 3);
	g.TopologicalSort();
}

/*
// Rest of the code would be to find out the difference in two dictionary words and form edge between two characters.
// This function fidns and prints order of characer from a sorted
// array of words. n is size of words[].  alpha is set of possible
// alphabets.
// For simplicity, this function is written in a way that only
// first 'alpha' characters can be there in words array.  For
// example if alpha is 7, then words[] should have only 'a', 'b',
// 'c' 'd', 'e', 'f', 'g'
void printOrder(string words[], int n, int alpha)
{
    // Create a graph with 'aplha' edges
    Graph g(alpha);
 
    // Process all adjacent pairs of words and create a graph
    for (int i = 0; i < n-1; i++)
    {
        // Take the current two words and find the first mismatching
        // character
        string word1 = words[i], word2 = words[i+1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            // If we find a mismatching character, then add an edge
            // from character of word1 to that of word2
            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j]-'a', word2[j]-'a');
                break;
            }
        }
    }
 
    // Print topological sort of the above created graph
    g.topologicalSort();
}
*/
