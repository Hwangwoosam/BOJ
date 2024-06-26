import java.util.*;
import java.io.*;

class Main{
    static int n,m,q;
    static int map[][];
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,1,-1};

    static class Pair{
        int x;
        int y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }

    static void imageProcessing(int x,int y, int c){
        boolean visited[][] = new boolean[n+1][m+1];

        Queue<Pair> q = new ArrayDeque<>();
        visited[x][y] = true;
        q.add(new Pair(x,y));

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if(visited[nx][ny]) continue;
                if(map[cur.x][cur.y] != map[nx][ny]) continue;
                
                visited[nx][ny] = true;
                q.add(new Pair(nx,ny));
            }
            
            map[cur.x][cur.y] = c;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String inp[] = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        m = Integer.parseInt(inp[1]);

        map = new int[n+1][m+1];

        for(int i = 1; i <= n; i++){
            inp = br.readLine().split(" ");
            for(int j = 0; j < m; j++){
                map[i][j+1] = Integer.parseInt(inp[j]);
            }
        }

        q = Integer.parseInt(br.readLine());

        for(int i = 0; i < q; i++){
            int x,y,c;
            inp = br.readLine().split(" ");
            x = Integer.parseInt(inp[0]);
            y = Integer.parseInt(inp[1]);
            c = Integer.parseInt(inp[2]);

            imageProcessing(x, y, c);
        }

        StringBuilder sb =  new StringBuilder("");
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sb.append(map[i][j]).append(" ");
            }
            sb.append("\n");
        }

        bw.append(sb.toString());
        bw.flush();

        br.close();
        bw.close();
    }
}