/*

LONGEST MOUNTAIN IN ARRAY
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 

Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?

*/


#include <vector>
#include <iostream> // Added for printing test results
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;

        int maxLength = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if arr[i] is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i;
                int right = i;

                // Move left pointer to find the start of the mountain
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }

                // Move right pointer to find the end of the mountain
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Update maxLength if a longer mountain is found
                maxLength = max(maxLength, right - left + 1);

                // Move the pointer to the next element after the mountain
                i = right;
            } else {
                // Skip non-peak elements
                i++;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> arr1;
    arr1.push_back(2);
    arr1.push_back(1);
    arr1.push_back(4);
    arr1.push_back(7);
    arr1.push_back(3);
    arr1.push_back(2);
    arr1.push_back(5);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(2);
    arr2.push_back(2);

    vector<int> arr3;
    arr3.push_back(1);
    arr3.push_back(2);
    arr3.push_back(1);
    arr3.push_back(3);
    arr3.push_back(2);
    arr3.push_back(1);

    // Test and print results
    cout << "Test case 1: " << sol.longestMountain(arr1) << endl;  // Output: 5
    cout << "Test case 2: " << sol.longestMountain(arr2) << endl;  // Output: 0
    cout << "Test case 3: " << sol.longestMountain(arr3) << endl;  // Output: 3

    return 0;
}
