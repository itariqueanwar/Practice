#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLength = 0;
        int left = 0, right = 0;
        std::unordered_set<char> seenChars;
        
        while (right < s.length()) {
            if (seenChars.find(s[right]) == seenChars.end()) {
                seenChars.insert(s[right]);
                maxLength = std::max(maxLength, right - left + 1);
                right++;
            } else {
                seenChars.erase(s[left]);
                left++;
            }
        }
        
        return maxLength;
    }
};
