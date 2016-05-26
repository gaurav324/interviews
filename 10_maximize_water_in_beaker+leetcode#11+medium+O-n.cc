// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Notes: 
// 
// What did we learn?
// It was easy O(n^2). Looked from the face of it that we might be able to do it in O(n) which was correct. Just had to think a little more.
// 

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int maxArea = 0;
    while (i < j) {
        if (min(height[i], height[j]) * (j - i) > maxArea) {
            maxArea = min(height[i], height[j]) * (j - i);
        }
        if (height[i] > height[j]) {
            --j;
        } else {
            i++;
        }
        continue;
    }
    return maxArea;
}

int main() {
	return maxArea({1, 2, 4, 2, 1});
}
