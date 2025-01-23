import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int[] t = new int[n];
        int[] b = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            t[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }

        long[] dp = new long[n];
        st = new StringTokenizer(br.readLine());
        dp[0] = Long.parseLong(st.nextToken());

        for (int i = 1; i < n; i++) {
            long c = Long.parseLong(st.nextToken());
            int prevIdx = lowerBound(t, 0, i + 1, t[i] - b[i]) - 1;

            dp[i] = Math.max(dp[i - 1], c);
            if (prevIdx >= 0) {
                dp[i] = Math.max(dp[i], dp[prevIdx] + c);
            }
        }

        System.out.println(dp[n - 1]);
    }

    private static int lowerBound(int[] arr, int start, int end, int key) {
        int low = start;
        int high = end;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (key <= arr[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
