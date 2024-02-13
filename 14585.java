import java.util.*;
import java.io.*;

class Main{
    static int n,m;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        boolean map[][] = new boolean[301][301];
        int dp[][] = new int[301][301];

        int maxLimit = 0;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = true;
            if(x == 0 || y == 0) dp[x][y] = m -x -y;
            maxLimit = Math.max(maxLimit, Math.max(x, y));
        }
        
        for(int i = 1; i <= maxLimit; i++){
            for(int j = 1; j <= maxLimit; j++){

                dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);

                if(map[i][j]){
                    int val = m - i - j;
                    if(val > 0){
                        dp[i][j] += val;
                    }
                }
            }
        }

        bw.append(dp[maxLimit][maxLimit] + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}