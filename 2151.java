import java.util.*;
import java.io.*;

class Main{
    static char[][] map;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static boolean[][][] visited;

    static int n,sx = -1,sy = -1,ex = -1,ey = -1;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        visited = new boolean[n][n][4];
        map = new char[n][n];

        for(int i = 0; i < n; i++){
            map[i] = br.readLine().toCharArray();

            for(int j = 0; j < n; j++){
                if(map[i][j] == '#'){
                   if(sx == -1){
                    sx = i;
                    sy = j;
                   }else{
                    ex = i;
                    ey = j;
                   }
                }
            }
        }

        bfs();
    }


    static void bfs(){
        PriorityQueue<Pair> q = new PriorityQueue<>();
        
        for(int i = 0; i < 4; i++) q.add(new Pair(sx,sy,i,0));
        

        while(!q.isEmpty()){
            Pair cur = q.poll();

            visited[cur.x][cur.y][cur.dir] = true;

            if(cur.x == ex && cur.y == ey){
                System.out.println(cur.mCnt);
                return;
            }

            int nx = cur.x + dx[cur.dir];
            int ny = cur.y + dy[cur.dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny][cur.dir]) continue;
            if(map[nx][ny] == '*') continue;

            if(map[nx][ny] == '!'){
                int right = cur.dir +1 >= 4 ? (cur.dir+1)%4 : cur.dir+1;
                int left = cur.dir - 1 >= 0 ? cur.dir-1 : cur.dir+3;
                // visited[nx][ny][right] = true;
                // visited[nx][ny][left] = true;

                q.add(new Pair(nx,ny,right,cur.mCnt+1));
                q.add(new Pair(nx,ny,left,cur.mCnt+1));
            }

            // visited[nx][ny][cur.dir] = true;
            q.add(new Pair(nx,ny,cur.dir,cur.mCnt));
        }
    }

    static class Pair implements Comparable<Pair>{
        int x;
        int y;
        int dir;
        int mCnt;

        Pair(int x,int y,int dir,int mCnt){
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.mCnt = mCnt;
        }

        @Override
        public int compareTo(Pair o){
            return this.mCnt - o.mCnt;
        }
    }
}