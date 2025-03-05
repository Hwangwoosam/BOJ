import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            int[] coins = new int[n+1];
            int[][] dp = new int[n+1][100001];
            for(int j = 0; j <=n; j++){
                Arrays.fill(dp[j],0);
            }

            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++){
                coins[j] = Integer.parseInt(st.nextToken());
                dp[j][coins[j]]++;
            }

            int target = Integer.parseInt(br.readLine());

            for(int j = 1; j <= n; j++){
                for(int p = 1; p <= target; p++){
                    if(p - coins[j] < 0){
                        dp[j][p] = dp[j-1][p];
                        continue;
                    }

                    dp[j][p] += dp[j-1][p] + dp[j][p-coins[j]];
                }
            }
            sb.append(dp[n][target]).append("\n");
        }

        System.out.print(sb.toString());
    }
}