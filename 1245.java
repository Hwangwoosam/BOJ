import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {-1,-1,-1,0,1,1,1,0};
    static int[] dy = {-1,0,1,1,1,0,-1,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j]) continue;
                if(checkCondition(i,j) && findLocation(i,j)){
                    // System.out.println(i + " " + j);
                    cnt++;
                }
            }
        }

        System.out.println(cnt);
    }

    static boolean checkCondition(int x, int y){
        for(int i = 0; i < 8;i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[x][y] < map[nx][ny]) return false;
        }
        // System.out.println("checkC: " + x + " " + y);
        return true;
    }

    static boolean findLocation(int x, int y){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));
        visited[x][y] = true;

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 8;i ++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[cur.x][cur.y] < map[nx][ny]) return false;
                if(visited[nx][ny]) continue;

                if(map[cur.x][cur.y] == map[nx][ny]){
                    q.add(new Pair(nx,ny));
                    visited[nx][ny] = true;
                }
                
            }
        }

        return true;
    }

    static class Pair{
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}