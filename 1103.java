import java.io.*;
import java.util.*;

class Main {
    static int N, M;
    static int[][] board;
    static int[][] dp;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        board = new int[N][M];
        dp = new int[N][M];
        visited = new boolean[N][M];
        
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                char c = line.charAt(j);
                board[i][j] = c == 'H' ? 0 : c - '0';
            }
        }
        
        int result = dfs(0, 0);
        System.out.println(result);
    }

    static int dfs(int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 0) {
            return 0;
        }
        
        if (visited[x][y]) {
            System.out.println(-1);
            System.exit(0);
            // return -1;
        }
        
        if (dp[x][y] != 0) {
            return dp[x][y];
        }
        
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i] * board[x][y];
            int ny = y + dy[i] * board[x][y];
            dp[x][y] = Math.max(dp[x][y], dfs(nx, ny) + 1);
        }
        
        visited[x][y] = false;
        
        return dp[x][y];
    }
}
