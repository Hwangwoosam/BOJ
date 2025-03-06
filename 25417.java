import java.util.*;
import java.io.*;

class Main{
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int[][] map = new int[5][5];
    static int r,c;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        
        StringTokenizer st;
        for(int i = 0; i < 5; i++){
            st = new  StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        int res = bfs(r,c);
        System.out.println(res);
    }

    static boolean checkRange(int nx, int ny){
        return nx < 0 || nx >= 5 || ny < 0 || ny >= 5;
    }

    static int bfs(int x,int y){
        int [][] dist = new int[5][5];
        for(int i = 0; i < 5; i++){
            Arrays.fill(dist[i],Integer.MAX_VALUE);
        }

        Queue<Student> q = new LinkedList<>();
        q.add(new Student(x,y,0));
        dist[x][y] = 0;

        while(!q.isEmpty()){
            Student cur = q.poll();

            if(map[cur.x][cur.y] == 1){
                return cur.dist;
            }

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(checkRange(nx,ny)) continue;
                if(map[nx][ny] == -1) continue;
                if(dist[nx][ny] <= cur.dist + 1) continue;
                
                q.add(new Student(nx,ny,cur.dist+1));
                dist[nx][ny] = cur.dist+1;
            }

            for(int i = 0; i < 4; i++){
                int nx = cur.x;
                int ny = cur.y;
                while(true){
                    int tmpX = nx + dx[i];
                    int tmpY = ny + dy[i];

                    if(checkRange(tmpX,tmpY) || map[tmpX][tmpY] == -1) {
                        break;
                    }
                    nx = tmpX;
                    ny = tmpY;

                    if(map[nx][ny] == 7){
                        break;
                    }
                }

                if(dist[nx][ny] > cur.dist + 1){
                    q.add(new Student(nx,ny,cur.dist+1));
                    dist[nx][ny] = cur.dist+1;
                }
            }
        }

        return -1;
    }

    static class Student{
        int x;
        int y;
        int dist;

        Student(int x, int y, int dist){
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}