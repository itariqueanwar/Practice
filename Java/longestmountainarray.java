import java.util.Scanner;

public class longestmountainarray {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the length of the array
        System.out.print("Enter the length of the array: ");
        int length = scanner.nextInt();

        // Read the elements of the array
        int[] arr = new int[length];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < length; i++) {
            arr[i] = scanner.nextInt();
        }

        // Create an instance of the class
        longestmountainarray solution = new longestmountainarray();

        // Call the method to find the longest mountain
        int longestMountainLength = solution.longestMountain(arr);

        // Print the result
        System.out.println("Length of the longest mountain subarray: " + longestMountainLength);
        
        scanner.close(); // Close the scanner to prevent resource leak
    }

    public int longestMountain(int[] arr) {
        int N = arr.length;
        int ans = 0;

        int[] pref = new int[N];
        int[] suff = new int[N];

        for (int i = 1; i < N; i++) {
            if (arr[i] > arr[i - 1]) {
                pref[i] = pref[i - 1] + 1;
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                suff[i] = suff[i + 1] + 1;
            }
        }
        for (int i = 1; i < N - 1; i++) {
            int left = pref[i];
            int right = suff[i];
            if (left > 0 && right > 0)
                ans = Math.max(ans, pref[i] + suff[i] + 1);
        }

        return ans;
    }
}
