import java.io.*;
import java.util.*;

class Main {
    static final int MOD = 100000;
    static int w, h;
    static int[][][][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        
        dp = new int[w+1][h+1][2][2];
        
        for (int i = 2; i <= w; i++) {
            dp[i][1][0][0] = 1;
        }
        for (int i = 2; i <= h; i++) {
            dp[1][i][1][0] = 1;
        }
        
        for (int i = 2; i <= w; i++) {
            for (int j = 2; j <= h; j++) {
                dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % MOD;
                dp[i][j][0][1] = dp[i-1][j][1][0];
                dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % MOD;
                dp[i][j][1][1] = dp[i][j-1][0][0];
            }
        }
                
        int result = (dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1]) % MOD;
        System.out.println(result);
    }
}
