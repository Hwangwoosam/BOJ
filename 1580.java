import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static char[][] map;
    static boolean[][][][] visited;
    static int asx,asy,bsx,bsy;
    static int[] dx = {-1,-1,-1,0,1,1,1,0,0};
    static int[] dy = {-1,0,1,1,1,0,-1,-1,0};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m][n][m];

        for(int i = 0; i < n; i++){
            map[i] = br.readLine().toCharArray();
            for(int j = 0; j < m; j++){
                if(map[i][j] == 'A'){
                    asx = i;
                    asy = j;
                    map[i][j] = '.';
                }else if(map[i][j] == 'B'){
                    bsx = i;
                    bsy = j;
                    map[i][j] = '.';
                }
            }
        }

        bfs();
    }

    static void bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(asx,asy,bsx,bsy,0));
        visited[asx][asy][bsx][bsy] = true;

        while(!q.isEmpty()){
            Pair cur = q.poll();
            // System.out.println(cur.ax + " " + cur.ay + "->" + cur.bx + " " + cur.by);
            if(cur.ax == bsx && cur.ay == bsy && cur.bx == asx && cur.by == asy){
                System.out.println(cur.cnt);
                return;
            }
            
            for(int i = 0; i < 9; i++){
                //1. a먼저 이동
                int anx = cur.ax + dx[i];
                int any = cur.ay + dy[i];

                if(anx < 0 || anx >= n || any < 0 || any >= m) continue;
                if(map[anx][any] == 'X') continue;

                //2. b 이동
                for(int j = 0; j < 9; j++){
                    int bnx = cur.bx + dx[j];
                    int bny = cur.by + dy[j];

                    if(bnx < 0 || bnx >= n || bny < 0 || bny >= m) continue;
                    if(map[bnx][bny] == 'X') continue;

                    //3. 같은 위치인지 확인
                    if(anx == bnx && any == bny) continue;
                    //4. 교차하는지 확인
                    if(anx == cur.bx && any == cur.by && bnx == cur.ax && bny == cur.ay) continue;
                    if(visited[anx][any][bnx][bny]) continue;

                    visited[anx][any][bnx][bny] = true;
                    q.add(new Pair(anx,any,bnx,bny,cur.cnt+1));
                }
            }
        }

        System.out.println(-1);
    }

    static class Pair{
        int ax;
        int ay;
        int bx;
        int by;
        int cnt;

        Pair(int ax,int ay, int bx, int by,int cnt){
            this.ax = ax;
            this.ay = ay;
            this.bx = bx;
            this.by = by;
            this.cnt = cnt;
        }
    }
}