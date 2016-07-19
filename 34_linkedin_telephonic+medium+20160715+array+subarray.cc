/**
Write a function that, given a list of integers (both positive and negative) returns the sum of the contiguous subsequence with maximum sum. Thus, given the sequence (1, 2, -4, 1, 3, -2, 3, -1) it should return 5.
*/

// {-4} return -4;
// {-4, -2} return -2;

// {1, 2, -3, 4, 5, -6}
int64_t ReturnMaxContigousSum(const std::vector<int> v)
{
    if (v.size() == 0) {
        return 0;
    }
    
    int64_t result = INT_MIN;
    int64_t sum = 0;
    for (int i=0; i < v.size(); ++i) {
        sum += v[i];
        if (sum > result) {
            result = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    
    return result;
}

// {1, 2, -4, 5, 6}
// {2, 3, 4}
// {-4}
// {-2, -3}

// {-2, 3, 5, -4, -3, 8, 7, -4, 3, -6}
// left = mult(-2, 3, 5, -4, -3, 8, 7, -4, 3)
// right = mult (3, 5, -4, -3, 8, 7, -4, 3, -6)
// return max(left, right)


// {-2, 13, 5, 0, -4, -3}
// left = -4 * -3
// right = 13 * 5
// return max(left, right)


// {-2, 1, 1, 0, -4, -3, -8, 0, -5, -2, 3, -5, 0}
// left = 30
// right = 30
int64_t ReturnMaxContiguousProduct(const std::vector<int> v)
{
    if (v.size() == 0) {
        return 0;
    }
    
    int64_t result = INT_MIN;
    int64_t p1 = 1;
    for (int i=0; i < v.size(); ++i) {
        p1 *= v[i];
        if (p1 > result) {
            result = p1;
        }
        if (v[i] == 0) {
            p1 = 1;
        }
    }
    
   p1 = 1;
   for (int i=v.size() - 1; i >= 0; --i) {
        p1 *= v[i];
        if (p1 > result) {
            result = p1;
        }
        if (v[i] == 0) {
            p1 = 1;
        }
    }
    
    return result;
}
