// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// NOTES:
// It was just a matter of gracefully handing the loops.

#include<vector>
vector<int> countBits(int num) {
    vector<int> ans;
    ans.resize(num + 1, 0);
    
    ans[0] = 0;
    if (num == 0) {
        return ans;
    }
    ans[1] = 1;
    if (num == 1) {
        return ans;
    }
    
    int i = 2;
    int j = 4;
    int diff = i;
    while(j <= num) {
        while(i < j) {
            ans[i] = ans[i - diff] + 1;
            ++i;
        }
        j = j << 1;
        diff = diff << 1;
    }
    while(i <= num) {
        ans[i] = ans[i - diff] + 1;
        ++i;
    }
    return ans;
}

int main() {
	vector<int> result = countBits(5);
}
