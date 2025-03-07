import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] weight;
    static int[] balls;
    static boolean[][] dp;
    public static void main (String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        weight = new int[n+1];
        dp = new boolean[n+1][15501];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            weight[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        balls = new int[m];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < m; i++){
            balls[i] = Integer.parseInt(st.nextToken());
            if(balls[i] > 15000){
                balls[i] = -1;
            }
        }
        
        checkWeight();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++){
            if(balls[i] == -1){
                sb.append("N ");
            }else if(dp[n][balls[i]]){
                sb.append("Y ");
            }else{
                sb.append("N ");
            }
        }

        System.out.println(sb.toString());
    }

    static void checkWeight(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 15000; j++){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                }else{
                    int cond1 = Math.abs(j-weight[i]);
                    int cond2 = j + weight[i];
                    if(cond1 == 0){
                        dp[i][j] = true;
                    }else if(dp[i-1][cond1] || dp[i-1][cond2]){
                        dp[i][j] = true;
                    }
                }
            }
        }
    }
}