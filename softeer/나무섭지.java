import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[][] map;
    static int[][] ghostMap;
    static boolean[][] visited;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static Point end,start;
    static List<Point> ghost;

    static class Point{
        int x;
        int y;

        public Point(int x,int y){
            this.x = x;
            this.y = y;
        }

        boolean isSame(int x, int y){
            if(this.x == x && this.y == y) return true;

            return false;
        }
    }

    static void moveGhost(){
        Queue<Point> q = new LinkedList <>();
        q.add(ghost.get(0));

        while (!q.isEmpty()) {
            int curX = q.peek().x;
            int curY = q.peek().y;
            q.poll();

            for(int i = 0; i < 4; i++){
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(ghostMap[curX][curY] + 1 >= ghostMap[nx][ny]) continue;
                if(ghostMap[curX][curY] + 1 >= ghostMap[end.x][end.y]) continue;
                ghostMap[nx][ny] = ghostMap[curX][curY] + 1;
                q.add(new Point(nx,ny));
            }
            
        }
    }

    static boolean findWay(){
        Queue<Point> q = new LinkedList <>();
        q.add(start);

        while (!q.isEmpty()) {
            int curX = q.peek().x;
            int curY = q.peek().y;
            q.poll();

            if(end.isSame(curX, curY)) return true;

            for(int i = 0; i < 4; i++){
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[nx][ny] == -1) continue;
                if(visited[nx][ny]) continue;

                map[nx][ny] = map[curX][curY] + 1;
                visited[nx][ny] = true;

                q.add(new Point(nx,ny));
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception  {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inp[] = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        m = Integer.parseInt(inp[1]);
        ghost = new ArrayList<>();

        map = new int[n][m];
        ghostMap = new int[n][m];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++){
            String st = br.readLine();
            Arrays.fill(ghostMap[i], Integer.MAX_VALUE);
            for(int j = 0; j < m; j++){
                if(st.charAt(j) == '#'){
                    map[i][j] = -1;
                }else if(st.charAt(j) == 'D'){
                    map[i][j] = Integer.MAX_VALUE;
                    end = new Point(i,j);
                }else if(st.charAt(j) == 'G'){
                    ghost.add(new Point(i,j));
                    ghostMap[i][j] = 0; 
                }else if(st.charAt(j) == 'N'){
                    start = new Point(i,j);
                    visited[i][j] = true;
                }
            }
        }

        if(findWay()){
            ghost.sort(
            Comparator.comparingInt(
                gh ->{
                    final int absRow = Math.abs(end.x - gh.x);
                    final int absCol = Math.abs(end.y - gh.y);
                    return absRow + absCol;
                }
            )
            );

            moveGhost();
            if(ghostMap[end.x][end.y] > map[end.x][end.y]) bw.append("Yes\n");
            else bw.append("No\n");
        }else{
            bw.append("No\n");
        }

        // System.out.println("-----GhostMap----");
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         System.out.print(ghostMap[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        bw.flush();

        br.close();
        bw.close();
    }
}