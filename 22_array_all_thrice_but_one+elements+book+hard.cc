// All elements in array occur thrice, but one.
//
// Very hard problem to solve in O(n) time and O(1) space.
//
// Solution:
// Idea is very unique. Think what happens when we do XOR. 
// - If there are odd numbers of 1's, we set the bit. If there are even number of 1's, bit is unset.
//   What does this mean?
//   - This basically says that if noOf1sCount % 2 is 1, we set the bit, otherwise don't.
//
// Taking this a step forward. Now, we start counting if noOf1sCount % 3 is (1 or 2). 
// In the end remainder two component should be zero, as 3 times occuring will become zero.
// Also the one time occuring, the only one left would remain in 1 remainder variable.
//
// So, how we change b1 and b2, we just drew a truth table.
// For instance, getting value of b2:
// b1 b2 a
// 0  *  * = 0
// 1  0  0 = 0 
// 1  0  1 = 1
// 1  1  0 = 1
// 1  1  1 = 0
// i.e. b2 = b1. (b ^ a)
// Similar truth table can be drawn for b1 also.
#include <vector>
#include <iostream>

using namespace std;

int solve(const vector<int>& vec) {
	int b1 = 0;
	int b2 = 0;
	for (auto a : vec) {
		int t = b1;
		b1 = (b2 & (~a)) + ((~b2) & (b1 | a));
		b2 = t & (b2 ^ a);
	}
	cout << "B2 was = " << b2;
	return b1;
}

int main() {
	vector<int> v = {10, 2, 2, 2, 10, 5, 1, 5, 10, 5};
	cout << "First one: " << solve(v) << endl;
	
	vector<int> v1 = {2, 5, 5, 5};
	cout << "Second one: " << solve(v1) << endl;	
}
