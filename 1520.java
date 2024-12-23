import java.util.*;
import java.io.*;

class Main{
    static int m,n;
    static int[][] map;
    static int[][] dp;
    static int ans = 0;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        map = new int[m][n];
        dp = new int[m][n];

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }

        ans = dfs(0,0);
        
        bw.append(ans + "\n");
        bw.flush();
    }

    static int dfs(int curX, int curY){
        if(curX == m-1 && curY == n-1) return 1;
        if(dp[curX][curY] != -1) return dp[curX][curY];

        dp[curX][curY] = 0;

        for(int i = 0; i < 4; i ++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(map[curX][curY] <= map[nx][ny]) continue;

            dp[curX][curY] = (dp[curX][curY] + dfs(nx,ny));
        }     

        return dp[curX][curY];  
    }
}