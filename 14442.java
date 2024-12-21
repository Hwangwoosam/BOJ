import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static int[][][] dist ;
    static String[] map;
    static int dx[] = {1,0,-1,0};
    static int dy[] = {0,1,0,-1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        map = new String[n];
        for(int i = 0; i < n; i++) map[i] = br.readLine();
        
        dist = new int [n][m][k+1];
        
        for (int[][] plane : dist) {
            for (int[] row : plane) {
                Arrays.fill(row, Integer.MAX_VALUE);
            }
        }

        findWay(0,0);

        // for(int i = 0; i < k; i++){
        //     for(int j = 0; j < n; j++){
        //         for(int c = 0; c < m; c++){
        //             System.out.print(dist[j][c][i] + " ");
        //             // bw.append(dist[j][c][i] + " ");
        //         }
        //         System.out.println();
        //     }
        // }

        int ans = Integer.MAX_VALUE;
        for(int i = 0; i <= k; i++){
            ans = Math.min(ans,dist[n-1][m-1][i]);
        }

        if(ans == Integer.MAX_VALUE) ans = -1;
        
        bw.append(ans + "\n");
        bw.flush();
    }

    static void findWay(int st, int end){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(st,end,k));
        dist[st][end][k] = 1;

        while(!q.isEmpty()){
            Pair cur = q.poll();
            
            // System.out.println(cur.x + " " + cur.y + " " + cur.k);

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if(map[nx].charAt(ny) == '0'){
                    if(dist[cur.x][cur.y][cur.k] + 1 < dist[nx][ny][cur.k]){
                        dist[nx][ny][cur.k] = dist[cur.x][cur.y][cur.k] + 1;

                        q.add(new Pair(nx,ny,cur.k));
                    }
                }else{
                    if(cur.k > 0){
                        if(dist[cur.x][cur.y][cur.k] + 1 < dist[nx][ny][cur.k-1]){
                            dist[nx][ny][cur.k-1] = dist[cur.x][cur.y][cur.k] + 1 ;
                            q.add(new Pair(nx,ny,cur.k-1));
                        }
                    }
                }

            }

        }
    }

    static class Pair{
        int x;
        int y;
        int k;

        Pair(int x,int y,int k){
            this.x = x;
            this.y = y;
            this.k = k;
        }
    }
}