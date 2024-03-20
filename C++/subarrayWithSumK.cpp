//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount; // Map to store prefix sum frequencies
        prefixSumCount[0] = 1; // Base case: Empty subarray with sum 0
        
        for (int i = 0; i < N; i++) {
            sum += Arr[i]; // Update prefix sum
            
            // Check if there exists a subarray ending at the current index with sum equal to k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            // Update prefix sum frequency
            prefixSumCount[sum]++;
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends