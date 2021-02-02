//Two Sum LeetCode

#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

/**
* Time complexity O(n). We traverse the list of elements twice which is O(n). 
* The hash table look up is O(1)
* Space complexity. O(n) The space required depends on the number of elements in the list.
*/
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m; //Number index
    map<int, int> ::iterator itr;
    vector<int> indexes;
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        int remain = target - nums[i];
        itr = m.find(remain);
        if (itr != m.end() && itr->second != i) {
            indexes.push_back(i);
            indexes.push_back(itr->second);
            return indexes;
        }
    }
    return indexes;
}

int main() {
    vector<int> vTest1 = { 3, 3 };
    int testTarget1 = 6;
    vector<int> expected1 = { 0, 1 };
    assert(twoSum(vTest1, testTarget1) == expected1);

    vector<int> vTest2 = { 3, 2, 4 };
    int testTarget2 = 6;
    vector<int> expected2 = { 1, 2 };
    assert(twoSum(vTest2, testTarget2) == expected2);
    return 0;
}
