import java.util.*;
import java.io.*;

class Main{
    static int [][] map;
    static int [][] cost;
    static int [] dx = {-1,0,1,0};
    static int [] dy = {0,-1,0,1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int idx = 1;
        while(true){
            int n = Integer.parseInt(br.readLine());

            if(n == 0) break;

            map = new int [n][n];
            cost = new int[n][n];
            for(int i = 0; i < n; i++){
                Arrays.fill(cost[i],Integer.MAX_VALUE);
            }

            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            bfs(n);
            sb.append("Problem ").append(idx).append(": ").append(cost[n-1][n-1]).append("\n"); 
            idx++;
        }

        System.out.print(sb.toString());
    }

    static void bfs(int n){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0));
        cost[0][0] = map[0][0];
        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(cost[nx][ny] <= cost[cur.x][cur.y] + map[nx][ny]) continue;

                cost[nx][ny] =  cost[cur.x][cur.y] + map[nx][ny];
                q.add(new Pair(nx,ny));
            }
        }
    }

    static class Pair{
        int x;
        int y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
}