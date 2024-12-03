import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] soldier = new int[n+1];
        int[] dp = new int[n+1];

        for(int i = 1; i <= n; i++) soldier[i] = Integer.parseInt(st.nextToken());
        
        int result = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = 1;
            for(int j = 1; j < i; j++){
                if(soldier[j] > soldier[i]){
                    dp[i] = Math.max(dp[i],dp[j] + 1);
                }
            }
            result = Math.max(result,dp[i]);
        }

        bw.append((n-result) + "\n");
        bw.flush();
    }
}