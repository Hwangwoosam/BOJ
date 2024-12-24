import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] dx = {0,-1,0,1};
    static int[] dy = {-1,0,1,0};
    static int[][] map;
    static int[][] room;
    static int[] area;
    static boolean[][] visited;
    static int cnt = 1;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[m][n];
        room = new int[m][n];
        visited = new boolean[m][n];
        area = new int[m*n+1];

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            Arrays.fill(room[i],0);
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(room[i][j] == 0){
                    area[cnt] = bfs(i,j,cnt);
                    cnt++;
                }
            }
        }

        int maxRoom = 0;
        for(int i = 1; i < cnt; i++){
            maxRoom = Math.max(maxRoom,area[i]);
        }
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(room[i][j] == room[nx][ny]) continue;

                    maxArea = Math.max(maxArea,area[room[i][j]] + area[room[nx][ny]]);
                }
            }
        }

        bw.append((cnt-1) + "\n");
        bw.append(maxRoom + "\n");
        bw.append(maxArea + "\n");
        bw.flush();
    }

    static int bfs(int x,int y,int num){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));

        int roomCnt = 0;
        visited[x][y] = true;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            room[cur.x][cur.y] = num;
            roomCnt++;

            for(int i = 0; i < 4; i++){
                int bit = 1 << i;
                if((map[cur.x][cur.y] & bit) != 0) continue;

                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(room[nx][ny] > 0) continue;

                visited[nx][ny] = true;
                q.add(new Pair(nx,ny));    
            }
        }

        return roomCnt;
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