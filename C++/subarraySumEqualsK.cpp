#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumCount;

        prefixSumCount[0] = 1; 
        
        for (int num : nums) {
            sum += num; 

            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};
