import java.util.*;
import java.io.*;


public class Main {
    private static int[] dx = {-1,1,0,0};
    private static int[] dy = {0,0,-1,1};
    private static int n,m;
    private static int[][] map,distance;
    private static boolean[][] visited;
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
        String[] size = br.readLine().split(" ");
        n = Integer.parseInt(size[0]);
        m = Integer.parseInt(size[1]);
        
        map = new int[n][m];
        distance = new int[n][m];
        visited = new boolean[n][m];

        int startX = -1,startY = -1;

        for(int i = 0; i < n; i++){
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            if(startX == -1 && startY == -1){
                for(int j = 0; j < m; j++){
                    if(map[i][j] == 2){
                        startX = i;
                        startY = j;
                        break;
                    }
                }
            }
        }
        
        bfs(startX,startY);

        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(!visited[i][j] && map[i][j] == 1){
                    bw.append(String.valueOf(-1) +" ");
                }else{
                    bw.append(String.valueOf(distance[i][j]) + " ");
                }
            }
            bw.append("\n");
        }
        
        bw.flush();
    }

    private static void bfs(int startX,int startY){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(startX,startY));
        visited[startX][startY] = true;

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nextX = cur.a + dx[i];
                int nextY = cur.b + dy[i];

                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
                if(map[nextX][nextY] == 0) continue;
                if(visited[nextX][nextY]) continue;

                q.add(new Pair(nextX,nextY));
                distance[nextX][nextY] = distance[cur.a][cur.b] + 1;
                visited[nextX][nextY] = true;
            }
        }
    }
}

class Pair{
        public int a,b;
        public Pair(int a,int b){
            this.a = a;
            this.b = b;
        } 
    }
