import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] dp = new int[c+101];
        Arrays.fill(dp, 100000000);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            int customer = Integer.parseInt(st.nextToken());
            for(int j = customer; j < c+101; j++){
                dp[j] = Math.min(dp[j],cost + dp[j-customer]);
            }
        }

        int ans = Integer.MAX_VALUE;
        for(int i = c; i < c + 101; i++){
            ans = Math.min(ans,dp[i]);
        }

        bw.append(ans + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}