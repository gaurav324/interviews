// Create copy of linked list which has Next and Random pointers.
//
// Solution:
// Create a hashtable which stores, Pointer->int, i.e. Node to distance from root.
// Then while creating copies, it store them new map int->Pointer. Before adding random
// pointers, it checks in map one, how far those were and create new node at same distance.
// This solution has O(n) Run and O(n) space complexity.
//
// This is not very link listy solution though.
// Better solution is to create a relation between new nodes and original nodes.
// N1 -> CN1 -> N2 -> CN2 -> ...
// Then iterate again, and set the random pointers.
// As last step create two different linked lists out of these.
struct RandomListNode {
	int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<RandomListNode*, int> howFar;
        RandomListNode *temp = head;
        int count = 0;
        while (temp != NULL) {
            howFar.insert(std::pair<RandomListNode*, int>(temp, count++));
            temp = temp->next;
        }
        
        temp = head;
        unordered_map<int, RandomListNode*> newNodes;
        count = 0;
        while(temp != NULL) {
            RandomListNode* newNode;
            if (newNodes.find(count) != newNodes.end()) {
                newNode = newNodes[count];
            } else {
                newNode = new RandomListNode(temp->label);
                newNodes.insert(std::pair<int, RandomListNode*>(count, newNode));
            }

            if (temp->next != NULL) {
                if (newNodes.find(howFar[temp->next]) == newNodes.end()) {
                    RandomListNode* x = new RandomListNode(temp->next->label);
                    newNodes.insert(std::pair<int, RandomListNode*>(count + 1, x));
                    newNodes[count + 1] = x;
                }
                newNodes[count]->next = newNodes[count + 1];
            }
            
            if (temp->random != NULL) {
                if (newNodes.find(howFar[temp->random]) == newNodes.end()) {
                    RandomListNode* x = new RandomListNode(temp->random->label);
                    newNodes.insert(std::pair<int, RandomListNode*>(howFar[temp->random], x));
                }
                newNodes[count]->random = newNodes[howFar[temp->random]];
            }
            
            ++count;
            temp = temp->next;
        }
        return newNodes[0];
    }
};
