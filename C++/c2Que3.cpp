long long FindMaxSum(long long arr[], int n) {
    // If there are no elements, return 0
    if (n == 0)
        return 0;
    // If there is only one element, return that element
    else if (n == 1)
        return arr[0];
    
    // Create an array to store the maximum sum of subsequence ending at each index
    long long arr2[n];
    
    // Initialize dp array with the first two elements of the input array
    arr2[0] = arr[0];
    arr2[1] = max(arr[0], arr[1]); // Maximum of the first two elements
    
    // Loop through the array starting from the third element
    for (int i = 2; i < n; i++) {
        // At each index, choose the maximum between:
        // 1. The maximum sum obtained so far (dp[i - 1])
        // 2. The sum of the current element and the maximum sum obtained two elements ago (dp[i - 2] + arr[i])
        arr2[i] = max(arr2[i - 1], arr2[i - 2] + arr[i]);
    }
    
    // Return the maximum sum of subsequence
    return arr2[n - 1];
}