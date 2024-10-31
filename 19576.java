import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Integer[] mineral = new Integer[n];
    
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) mineral[i] = Integer.parseInt(st.nextToken());
        
        Arrays.sort(mineral);

        int[] dp = new int[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(mineral[i]% mineral[j] == 0){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int elem : dp) {
            ans = Math.max(ans,elem);
        }
        bw.append((n-ans) + "\n");
        bw.flush();
    }
}