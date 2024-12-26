import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int ans = Integer.MAX_VALUE;
    static int[][] map;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static ArrayList<Pair> virus;
    static ArrayList<Pair> selected;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        virus = new ArrayList<>();
        selected = new ArrayList<>();

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 2) {
                    // System.out.println(i + " " + j);
                    map[i][j] = 0;
                    virus.add(new Pair(i,j));
                }
            }
        }

        dfs(0);

        if(ans == Integer.MAX_VALUE) ans = -1;

        bw.append(ans + "\n");
        bw.flush();
    }

    static void dfs(int idx){
        if(selected.size() == m) {
            ans = Math.min(ans,findway());
            return;
        }
        // System.out.println(selected.size() + " " + virus.size());

        for(int i = idx; i < virus.size(); i++){
            Pair cur = virus.get(i);
            selected.add(cur);
            dfs(i+1);
            selected.remove(cur);
        }
    }

    static int findway(){
        Queue<Pair> q = new LinkedList<>();
        int [][] time = new int[n][n];
        boolean[][] visited = new boolean[n][n];
        for(int i = 0; i < m; i++) {
            q.add(selected.get(i));
            int x = selected.get(i).x;
            int y = selected.get(i).y;
            visited[x][y] = true;
            time[x][y] = 0;
        }

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(map[nx][ny] == 1) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = true;
                time[nx][ny] = time[cur.x][cur.y] + 1;
                q.add(new Pair(nx,ny));
            }
        }

        int maxTime = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] != 1 && visited[i][j] == false){
                    return Integer.MAX_VALUE;
                }

                maxTime = Math.max(maxTime,time[i][j]);
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         System.out.print(time[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        // System.out.println("============");
    
        return maxTime;
    }

    static class Pair{
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}