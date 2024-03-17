/*

One Integer
You are given a list of integers nums. You can reduce the length of nums by taking any two integers, removing them, and appending their sum to the end. The cost of doing this is the sum of the two integers you removed.

Print the minimum total cost of reducing nums to one integer.

sample input: nums = [1, 2, 3, 4, 5]

sample output: 33

Explanation:

We take 1 and 2 out to get [3, 4, 5, 3]

We take 3 and 3 out to get [4, 5, 6]

We take 4 and 5 out to get [6, 9]

We take 6 and 9 out to get [15]

The sum is 33 = 1 + 2 + 3 + 3 + 4 + 5 + 6 + 9

Constraints:

1 <= n <= 10^5
Edit


*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCost(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0;
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    for (int i = 0; i < n - 1; i++) {
        pq.push({nums[i] + nums[i + 1], {i, i + 1}});
    }
    
    int total_cost = 0;
    
    while (pq.size() > 1) {
        auto top = pq.top();
        pq.pop();
        
        int i = top.second.first;
        int j = top.second.second;
        
        total_cost += top.first;
        
        if (i > 0) {
            pq.push({nums[i - 1] + nums[j], {i - 1, j}});
        }
        
        if (j < n - 1) {
            pq.push({nums[i] + nums[j + 1], {i, j + 1}});
        }
    }
    
    return total_cost;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << minCost(nums) << endl;
    
    return 0;
}