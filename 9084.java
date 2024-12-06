import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            int[] coins = new int[n+1];

            st = new StringTokenizer(br.readLine());
            for(int j = 1; j < n+1; j++) coins[j] = Integer.parseInt(st.nextToken());

            int m = Integer.parseInt(br.readLine());
            
            int[] dp = new int[m+1];
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <=m; k++){
                    if(k-coins[j] > 0){
                        dp[k] = dp[k] + dp[k-coins[j]];
                    }else if(k-coins[j] == 0){
                        dp[k]++;
                    }
                }
            }

            bw.append(dp[m] + "\n");
        }

        bw.flush();
    }
}