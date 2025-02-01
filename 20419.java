import java.util.*;
import java.io.*;

class Main{
    static int r,c,k;
    static char[][]map;
    static boolean[][][] visited;
    static int [] dx = {-1,0,1,0};
    static int [] dy = {0,1,0,-1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new char[r][c];
        visited = new boolean[r][c][4];

        for(int i = 0 ; i < r; i++) map[i] = br.readLine().toCharArray();
        if(findWay()) System.out.println("Yes");
        else System.out.println("No");
    }

    static boolean findWay(){

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0,0));
        visited[0][0][0] = true;

        while(!q.isEmpty()){
            Pair cur = q.poll();
            // System.out.println(cur.x + " " + cur.y + " " + cur.k);
            if(cur.x == r-1 && cur.y == c-1) return true;

            int dir = -1;
            if(map[cur.x][cur.y] == 'U') dir = 0;
            else if(map[cur.x][cur.y] == 'R') dir = 1;
            else if(map[cur.x][cur.y] == 'D') dir = 2;
            else dir = 3;

            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(!visited[nx][ny][cur.k]){
                    q.add(new Pair(nx,ny,cur.k));
                    visited[nx][ny][cur.k] = true;
                }
            }

                // left
            if(k > 0){
                if((cur.k & 1) == 0){
                    int leftDir = dir - 1 >= 0 ? dir - 1 : dir + 3;
                    nx = cur.x + dx[leftDir];
                    ny = cur.y + dy[leftDir];
                    int nk = cur.k | 1;
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                        if(!visited[nx][ny][nk]){
                            // System.out.println("left: " + nx + " " + ny);
                            q.add(new Pair(nx,ny,nk));
                            visited[nx][ny][nk] = true;
                        }
                    }
                }
                // right
                if((cur.k & 2) == 0){
                    int rightDir = dir + 1 < 4 ? dir + 1 : (dir + 1)%4;
                    nx = cur.x + dx[rightDir];
                    ny = cur.y + dy[rightDir];
                    int nk = cur.k | 2;
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                        if(!visited[nx][ny][nk]){
                            // System.out.println("right");
                            q.add(new Pair(nx,ny,nk));
                            visited[nx][ny][nk] = true;
                        }
                    }
                }
            }
        }

        return false;
    }

    static class Pair {
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