import java.util.*;
import java.io.*;

class Main{

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int[] prefixSum = new int[n+1];
        Arrays.fill(prefixSum,0);

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i-1] + Integer.parseInt(st.nextToken());
        }

        int start = 1;
        int end = 1;
        int ans = Integer.MAX_VALUE;
        int sum = 0;
        while(start <= end && end <= n){
            
            sum = prefixSum[end] - prefixSum[start-1];
            if(sum < s){
                end++;
            }else{
                ans = Math.min(ans,end-start+1);
                start++;
            }
        }
        if(ans == Integer.MAX_VALUE) ans = 0;
        bw.append(ans + "\n");
        bw.flush();
    }
}