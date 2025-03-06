import java.util.*;
import java.io.*;

class Main{
    static int w,h;
    static int [][] map;
    static boolean [][] visited;
    static int [][] sides;
    static int[][] odd = {{-1,0},{0,-1},{1,0},{1,1},{0,1},{-1,1}};
    static int[][] even = {{-1,-1},{0,-1},{1,-1},{1,0},{0,1},{-1,0}};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        map = new int[h+2][w+2];
        sides = new int[h+2][w+2];
        visited = new boolean[h+2][w+2];

        for(int i = 1; i <= h; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= w; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        bfs();

        // System.out.println(ans);
    }

    static void bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0));
        visited[0][0] = true;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int nx = cur.x;
            int ny = cur.y;
            for(int i = 0; i < 6; i++){
                int px;
                int py;
                if(nx % 2 == 0) {
                    px = nx + even[i][0];
                    py = ny + even[i][1];
                }
                else {
                    px = nx + odd[i][0];
                    py = ny + odd[i][1];
                }
                if(px >= 0 && px <= h + 1 &&  py >= 0 && py <= w + 1){
                    if(!visited[px][py]){
                        if(map[px][py] == 0){
                            visited[px][py] = true;
                            q.add(new Pair(px, py));
                        }
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(map[i][j] == 0)
                    continue;
                for(int t = 0; t < 6; t++){
                    int nx; int ny;
                    if(i % 2 == 0){
                        nx = i + even[t][0];
                        ny = j + even[t][1];
                    }else{
                        nx = i + odd[t][0];
                        ny = j + odd[t][1];
                    }
                    if(visited[nx][ny])
                        sum++;
                }
            }
        }
        System.out.println(sum);
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