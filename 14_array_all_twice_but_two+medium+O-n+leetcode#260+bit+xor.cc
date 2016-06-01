// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
////////////////////////////////////////////////////////////////////
// Notes: 
// This was harder than the normal XOR case. In this one, one had to think through how we could split
// numbers into two groups.
#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int> nums) {
    int result = 0;
    for (auto n : nums) {
        result ^= n;
    }
    int selection = 1;
    while (!(selection & result)) {
        selection <<= 1;
    }
    int r1 = 0, r2 = 0;
    for (auto n : nums) {
        if (n & selection) {
            r1 ^= n;
        } else {
            r2 ^= n;
        }
    }
    return {r1, r2};
}

int main() {
	singleNumber({2, 2, 3});
}
