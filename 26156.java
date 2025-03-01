import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int[][] dp;
    static final int MOD = 1000000007;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        String inp = br.readLine();

        dp = new int[n+1][5];
        dp[0][0] = 1;
        for(int i = 1; i < n +1; i++){
            char c = inp.charAt(i-1);
            dp[i][0] = (dp[i-1][0] * 2) % MOD;

            if(c == 'R'){
                dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
            }else{
                dp[i][1] = dp[i-1][1] % MOD;
            }

            if(c == 'O'){
                dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % MOD;
            }else{
                dp[i][2] = dp[i-1][2] % MOD;
            }

            if(c == 'C'){
                dp[i][3] = (dp[i-1][2] + dp[i-1][3]) % MOD;
            }else{
                dp[i][3] = dp[i-1][3] % MOD;
            }
            
            if(c == 'K'){
                dp[i][4] = (dp[i-1][3] + dp[i-1][4]) % MOD;
            }else{
                dp[i][4] = dp[i-1][4] % MOD;
            }
        }

        System.out.println(dp[n][4]);
    }
}