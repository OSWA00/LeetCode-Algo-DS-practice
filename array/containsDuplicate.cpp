#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/**
* Time complexity:O(n log n), sorting is O(n log n) and traversing the array is O(n)
* Space Complexity: O(1) heapsort usually costs O(1) auxiliary space
*/
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // N * log_2(N) 
    for (int i = 1; i < nums.size(); i++) { // O(N)
        int prev = nums[i - 1]; //O(1)
        if (nums[i] == prev) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> test1 = { 1,2,3,1 };
    assert(containsDuplicate(test1) == true);

    vector<int> test2 = { 1,2,3,4 };
    assert(containsDuplicate(test2) == false);

    vector<int> test3 = { 1,1,1,3,3,4,3,2,4,2 };
    assert(containsDuplicate(test3) == true);
    return 0;
}
