import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[][] map;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int ans = 0;
    static int route = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 0) {
                    continue;
                }
                bfs(i,j);
            }
        }

        System.out.println(ans);
    }

    static void bfs(int sx, int sy){
        boolean[][] visited = new boolean[n][m];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sx,sy,0));
        visited[sx][sy] = true;

        //map[sx][sy] = start

        while(!q.isEmpty()){
            Pair cur = q.poll();

            if(cur.move >= route){
                if(cur.move > route){
                    ans = map[sx][sy] + map[cur.x][cur.y];
                }else{
                    ans = Math.max(ans,map[sx][sy] + map[cur.x][cur.y]);
                }

                route = cur.move;
            }

            for(int i =0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[nx][ny] == 0) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = true;
                
                q.add(new Pair(nx,ny,cur.move+1));
            }
        }


    }

    static class Pair{
        int x;
        int y;
        int move;

        Pair(int x, int y, int move){
            this.x = x;
            this.y = y;
            this.move = move;
        }
    }
}