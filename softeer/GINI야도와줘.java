import java.util.*;
import java.io.*;

class Main{

    static class Pair{
        int x;
        int y;

        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }

    static int r,c;
    static int endX,endY,startX,startY;
    static char map[][];
    static int rain[][], user[][];
    static boolean visitedRain[][],visitedUser[][];
    static Queue<Pair> rains = new ArrayDeque<>();

    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,1,-1};

    static void setRain(){
        while (!rains.isEmpty()) {
            Pair cur = rains.poll();
            
            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visitedRain[nx][ny]) continue;
                if(map[nx][ny] != '.') continue;

                visitedRain[nx][ny] = true;
                rain[nx][ny] = rain[cur.x][cur.y] + 1;
                rains.add(new Pair(nx, ny));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inp[] = br.readLine().split(" ");
        r = Integer.parseInt(inp[0]);
        c = Integer.parseInt(inp[1]);

        map = new char[r][c];
        rain = new int[r][c];
        user = new int[r][c];
        visitedRain = new boolean[r][c];
        visitedUser = new boolean[r][c];

        for(int i = 0; i < r; i++){
            Arrays.fill(rain[i],Integer.MAX_VALUE);
            Arrays.fill(user[i],Integer.MAX_VALUE);
            Arrays.fill(visitedRain[i], false);
            Arrays.fill(visitedUser[i],false);
        }

        for(int i = 0; i < r; i++){
            String mapInfo = br.readLine();
            for(int j = 0; j < c; j++){
                map[i][j] = mapInfo.charAt(j);
                if(map[i][j] == 'H'){
                    endX = i;
                    endX = j;
                }else if(map[i][j] == '*'){
                    rains.add(new Pair(i, j));
                    visitedRain[i][j] = true;
                    rain[i][j] = 0;
                }else if(map[i][j] == 'W'){
                    startX = i;
                    startY = j;
                    map[i][j] = '.';
                    visitedUser[i][j] = true;
                    user[i][j] = 0;
                }
            }
        }

        if(!rains.isEmpty()){
            setRain();
        }
        
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(startX, startY));

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visitedUser[nx][ny]) continue;
                if(map[nx][ny] != '.' && map[nx][ny] != 'H') continue;
                if(rain[nx][ny] <= user[cur.x][cur.y] + 1) continue;

                visitedUser[nx][ny] = true;
                user[nx][ny] = user[cur.x][cur.y] + 1;
                q.add(new Pair(nx, ny));
            }

        }


        if(user[endX][endY] == Integer.MAX_VALUE){
            bw.append("FAIL\n");
        }else{
            bw.append(user[endX][endY] + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
