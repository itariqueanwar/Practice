#include <iostream>
#include <unordered_set>
#include <vector>

class LongestSubsequence {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        for (int element : set) {
            int parent = element - 1;
            if (set.find(parent) == set.end()) {
                int next_no = element + 1;
                int cnt = 1;
                while (set.find(next_no) != set.end()) {
                    cnt++;
                    next_no++;
                }
                ans = std::max(ans, cnt);
            }
        }
        return ans;
    }
};

int main() {
    LongestSubsequence ls;
    std::vector<int> nums;
    
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;
    nums.resize(n);

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "Longest consecutive subsequence length: " << ls.longestConsecutive(nums) << std::endl;

    return 0;
}
