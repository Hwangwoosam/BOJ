import java.util.*;
import java.io.*;

class Main{

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long[] sum = new long[n+1];
        long[] left = new long[m];
        Arrays.fill(sum,0);

        st = new StringTokenizer(br.readLine());

        long ans = 0;
        for(int i = 1 ; i <= n; i++){
            sum[i] = (sum[i-1] + Long.parseLong(st.nextToken()))%m;

            if(sum[i] == 0) ans ++;

            left[(int)sum[i]]++;
        }
        for(int i = 0; i < m; i++){
            if(left[i] > 1){
                ans += (left[i]*(left[i]-1)/2);
            }
        }

        bw.append(ans + "\n");
        bw.flush();
    }
}