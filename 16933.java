import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static char[][] map;
    static boolean[][][] visited;
    static int [] dx = {1,0,-1,0};
    static int [] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m][k+1];

        for(int i = 0; i < n; i++) map[i] = br.readLine().toCharArray();

        bw.append(bfs() + "\n");
        bw.flush();
    }

    static int bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0,0,1,false));
        visited[0][0][0] = true;

        while(!q.isEmpty()){
            Pair cur = q.poll();

            if(cur.x == n-1 && cur.y == m-1) return cur.dist;

            // System.out.println(cur.x + " " + cur.y);
            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
               
                if(map[nx][ny] == '1' && cur.k < k){     
                  if(!cur.state){   // day
                    if(!visited[nx][ny][cur.k+1]){
                        visited[nx][ny][cur.k+1] = true;
                        q.add(new Pair(nx,ny,cur.k+1,cur.dist+1,!cur.state));
                    }
                  }else{            // night
                    q.add(new Pair(cur.x,cur.y,cur.k,cur.dist+1,!cur.state));
                  }
                }else if(map[nx][ny] == '0'){
                    if(!visited[nx][ny][cur.k]){
                        visited[nx][ny][cur.k] = true;
                        q.add(new Pair(nx,ny,cur.k,cur.dist+1,!cur.state));
                    }
                }
            }
        }

        return -1;
    }

    static class Pair{
        int x;
        int y;
        int k;
        int dist;
        boolean state;

        Pair(int x,int y,int k,int dist,boolean state){
            this.x = x;
            this.y = y;
            this.k = k;
            this.dist = dist;
            this.state = state;
        }
    }
}