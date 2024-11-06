import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        
        int[] errorLine = new int[n];
        Arrays.fill(errorLine,0);

        for(int i = 0; i < m; i++){
            int idx = Integer.parseInt(st.nextToken());
            errorLine[idx-1]++;
        }

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int errCnt = 0;
        int minCnt = 100000000;
        for(int i = 0; i < x; i++) if(errorLine[i] > 0) errCnt++; 
        
        for(int i = x; i <= n; i++){
            minCnt = Math.min(minCnt,errCnt);
            if(i == n) break;

            errCnt -= errorLine[i-x];
            errCnt += errorLine[i];
        }
        

        bw.append(Math.min(m-minCnt,m-y) + "\n");
        bw.flush();
    }
}