import java.util.*;
import java.io.*;

class Main{
    static long[][] prefixSum;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        prefixSum = new long[n+1][m+1];
      
        for(int i = 1; i <= n; i++){
            String inp = br.readLine();
            for(int j = 1; j <= m; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + (inp.charAt(j-1)-'0');
            }
        }
        
        Long ans = 0L;
        for(int i = 1; i <=m-2; i++){
            for(int j = i+1; j <= m-1; j++){
                long r1 = sum(1,1,n,i);
                long r2 = sum(1,i+1,n,j);
                long r3 = sum(1,j+1,n,m);

                if(ans < r1*r2*r3) ans = r1*r2*r3; 
            }
        }

        for(int i = 1; i <=n-2; i++){
            for(int j = i+1; j <= n-1; j++){
                long r1 = sum(1,1,i,m);
                long r2 = sum(i+1,1,j,m);
                long r3 = sum(j+1,1,n,m);

                if(ans < r1*r2*r3) ans = r1*r2*r3;
            }
        }

        for(int i = 1; i <= n-1; i++){
            for(int j = 1; j <= m-1; j++){
                long r1 = sum(1,1,n,j);
                long r2 = sum(1,j+1,i,m);
                long r3 = sum(i+1,j+1,n,m);

                if(ans < r1*r2*r3) ans = r1*r2*r3;

                r1 = sum(1,1,i,j);
                r2 = sum(i+1,1,n,j);
                r3 = sum(1,j+1,n,m);

                if(ans < r1*r2*r3) ans = r1*r2*r3;

                r1 = sum(1,1,i,m);
                r2 = sum(i+1,1,n,j);
                r3 = sum(i+1,j+1,n,m);
                
                if(ans < r1*r2*r3) ans = r1*r2*r3;

                r1 = sum(1,1,i,j);
                r2 = sum(1,j+1,i,m);
                r3 = sum(i+1,1,n,m);

                if(ans < r1*r2*r3) ans = r1*r2*r3;
            }
        }

        bw.append(ans + "\n");
        bw.flush();
    }

    static Long sum(int x1,int y1, int x2,int y2){
        return prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1];
    }
}