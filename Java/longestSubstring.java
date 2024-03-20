import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        int left = 0, right = 0;
        HashSet<Character> seenChars = new HashSet<>();
        
        while (right < s.length()) {
            if (!seenChars.contains(s.charAt(right))) {
                seenChars.add(s.charAt(right));
                maxLength = Math.max(maxLength, right - left + 1);
                right++;
            } else {
                seenChars.remove(s.charAt(left));
                left++;
            }
        }
        
        return maxLength;
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test cases
        System.out.println(solution.lengthOfLongestSubstring("abcabcbb")); // Output: 3
        System.out.println(solution.lengthOfLongestSubstring("bbbbb"));    // Output: 1
        System.out.println(solution.lengthOfLongestSubstring("pwwkew"));   // Output: 3
    }
}
