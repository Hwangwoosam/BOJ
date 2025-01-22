import java.util.*;
import java.io.*;

class Main{
    static int n,h,d;
    static char[][] map;
    static int[][] dist;
    static int sx,sy;
    static int res = Integer.MAX_VALUE;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        
        map = new char[n][n];
        dist = new int[n][n];

        for(int i = 0; i < n; i++){
            map[i] = br.readLine().toCharArray();
            for(int j = 0; j < n; j++){
                if(map[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
            }
        }

        bfs();
        
        if(res == Integer.MAX_VALUE) res = -1;
        System.out.println(res);
    }

    static void bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sx,sy,0,h,0));
        dist[sx][sy] = h;

        while(!q.isEmpty()){
            Pair cur = q.poll();
         
            for(int i = 0; i < 4; i++){
                int nx = cur.x +dx[i];
                int ny = cur.y +dy[i];
    
                int curH = cur.health;
                int curUmb = cur.umb;   
    
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                
                if(map[nx][ny] == 'E'){
                    res = Math.min(res,cur.cnt+1);
                    continue;
                }

                if(map[nx][ny] == 'U') curUmb = d;
                
                if(curUmb > 0) curUmb--;
                else curH--;

                if(curH <= 0) continue;

                if(dist[nx][ny] < curH + curUmb){
                    dist[nx][ny] = curH + curUmb;
                    q.add(new Pair(nx,ny,curUmb,curH,cur.cnt+1));
                }
            }
        }
    }
    

    static class Pair implements Comparable<Pair>{
        int x;
        int y;
        int umb;
        int health;
        int cnt;

        Pair(int x,int y,int umb,int health,int cnt){
            this.x = x;
            this.y = y;
            this.umb = umb;
            this.health = health;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Pair a){
            return this.x - a.x;
        }
    }
}