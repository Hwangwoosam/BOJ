import java.io.*;
import java.util.*;

class Main{
    static long MOD = 1000000007;
    static long[] dp;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        dp = new long[5002];
        int t = Integer.parseInt(br.readLine());        
        
        dp[0] = 1;
        for(int i = 1; i <= 5001; i++){
            for(int j = 0; j < i; j++){
                dp[i] = (dp[i] + (dp[j]*dp[i-1-j])%MOD ) % MOD;
            }
            // System.out.println( i + ": " +dp[i]);
        }

        for(int i = 0; i < t; i++){
            int num = Integer.parseInt(br.readLine());
            System.out.println(dp[num+1]);
        }

    }
}