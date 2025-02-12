import java.util.*;
import java.io.*;

class Main{
    static int n,m,cheeseNum;
    static int[][] map;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        map = new int[n][m];

        cheeseNum = 0;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1) cheeseNum++;
            }
        }

        int times = 0;
        int cnt = 0;
        boolean [][] visited;
        while(cheeseNum > 0){
            visited = new boolean[n][m];

            cnt = meltingCheese(visited);
            // System.out.println(cnt);
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++){
            //         System.out.print(map[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            cheeseNum -= cnt;
            times++;
            // break;
        }

        System.out.println(times);
        System.out.println(cnt);
    }

    static int meltingCheese(boolean[][] visited){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0));
        visited[0][0] = true;

        int cnt = 0;
        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny]) continue;

                if(map[nx][ny] == 1){
                    cnt++;
                    map[nx][ny] = 0;
                    visited[nx][ny] = true;
                    continue;
                }

                q.add(new Pair(nx,ny));
                visited[nx][ny] = true;
            }

        }
        return cnt;
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