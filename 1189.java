import java.util.*;
import java.io.*;

class Main{
    static char[][] map;
    static boolean[][] visited;
    static int r,c,k;
    static int res = 0;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        map = new char[r][c];
        visited = new boolean[r][c];
        for(int i = 0; i < r; i++) map[i] = br.readLine().toCharArray();
        
        visited[r-1][0] = true;
        dfs(r-1,0,0);

        System.out.println(res);
    }

    static void dfs(int curX,int curY,int cnt){
        if(curX == 0 && curY == c-1){
            if(cnt == k-1) res++;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 'T') continue;
            
            visited[nx][ny] = true;
            dfs(nx,ny,cnt+1);
            visited[nx][ny] = false;
        }
    }
}