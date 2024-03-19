import java.util.HashSet;
import java.util.Scanner;

public class longestsubsequence {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the length of the array:");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        
        longestsubsequence ls = new longestsubsequence();
        System.out.println("Longest consecutive subsequence length: " + ls.longestConsecutive(nums));
    }

    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int x : nums) {
            set.add(x);
        }
        int ans = 0;
        for(int element : set) {
            int parent = element - 1;
            if(!set.contains(parent)) {
                int next_no = element + 1;
                int cnt = 1;
                while (set.contains(next_no)){
                    cnt++;
                    next_no++;
                }
                ans = Math.max(ans,cnt);
            }
        }
        return ans;
    }
}

