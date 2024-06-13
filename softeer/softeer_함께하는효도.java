import java.io.*;
import java.util.*;

class Main{
    public static final int cnt = 4;
    public static int[] dx = new int[]{0,0,1,-1};
    public static int[] dy = new int[]{1,-1,0,0};
    public static int[][] map;
    public static int n,m, answer = 0;
    public static Point[] friendPoint;
    public static List<List<Point>>[] routes;
    public static List<Point> visited = new ArrayList<>();

    static class Point{
        int x;
        int y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }

        public boolean isSame(Point point) {
            if (this.x == point.x && this.y == point.y) {
                return true;
            }
            return false;
        }
    }

    public static boolean isVisited(List<Point> visited, Point p){
        for(Point t : visited){
            if(p.isSame(t)) return true;
        }

        return false;
    }

    public static void findAllRoute(int idx, int curX, int curY, List<Point> visited){
        if(visited.size() == cnt){
            routes[idx].add(new ArrayList(visited));
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            Point np = new Point(nx,ny);
            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if(isVisited(visited,np)) continue;

            visited.add(np);
            findAllRoute(idx, nx, ny, visited);
            visited.remove(visited.size()-1);
        }
    }

    public static int getScore(List<List<Point>> route){
        int sum = 0;
        int copyMap[][] = new int[21][21];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                copyMap[i][j] = map[i][j];
            }
        }

        for(List<Point> r : route){
            for(Point p : r){
                sum += copyMap[p.x][p.y];
                copyMap[p.x][p.y] = 0;
            }
        }
        return sum;
    }

    public static void combination(int idx, List<List<Point>> route){
        if(idx == m){
            answer = Integer.max(answer, getScore(route));
            return;
        }
        for(List<Point> r : routes[idx]){
            route.add(r);
            combination(idx+1, route);
            route.remove(route.size()-1);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String inp[] = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        m = Integer.parseInt(inp[1]);
        map = new int[n+1][n+1];
        friendPoint = new Point[m];
        routes = new ArrayList[m];

        for(int i = 0; i < n; i++){
            String st[] = br.readLine().split(" ");
            for(int j = 0; j < n; j++){
                int num = Integer.parseInt(st[j]);
                map[i+1][j+1] = num;
            }
        }

        for(int i = 0; i < m; i++){
            routes[i] = new ArrayList<List<Point>>();
            inp = br.readLine().split(" ");
            int x = Integer.parseInt(inp[0]);
            int y = Integer.parseInt(inp[1]);
            friendPoint[i] = new Point(x,y);
        }

        for(int i = 0; i < m; i++){
            visited.add(friendPoint[i]);
            findAllRoute(i, friendPoint[i].x, friendPoint[i].y, visited);
            visited.clear();
        }

        List<List<Point>> result = new ArrayList<>();
        combination(0, result);

        bw.append(answer + "\n");
        bw.flush();
    }


}