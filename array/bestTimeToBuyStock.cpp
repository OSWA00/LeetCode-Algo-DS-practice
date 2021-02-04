#include <vector>
#include <algorithm>
#include <cassert>
#include  <climits>

using namespace std;

/**
* Time complexity O(N), we only have to traverse once the array
* Space complexity O(N), The space required depends on the number of elements in the list.
*/
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minValue = INT_MAX;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minValue) {
            minValue = prices[i];
        }
        else if (prices[i] - minValue > maxProfit) {
            maxProfit = prices[i] - minValue;
        }
    }
    return maxProfit;
}


int main() {
    vector<int> test1 = { 7,1,5,3,6,4 };
    assert(maxProfit(test1) == 5);

    vector<int> test2 = { 7,6,4,3,1 };
    assert(maxProfit(test2) == 0);

    return 0;
}
