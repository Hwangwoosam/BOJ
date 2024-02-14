import java.util.*;
import java.io.*;

class Main{

    static int map[][] = new int[21][21];
    static int dir[][] = {{-1,-1},{1,1},{-1,1},{1,-1},{0,1},{0,-1},{1,0},{-1,0}};
    static int ans = -1;

    static class Pair{
        int x;
        int y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    static boolean count(int curX,int curY,int dirNum){
        int cnt = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(curX, curY));

        // System.out.println("cur(" + dirNum +") : {" + curX +"," + curY+"}");
        // System.out.println("map_cur: " + map[curX][curY]);
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int nx = cur.x + dir[dirNum][0];
            int ny = cur.y + dir[dirNum][1];
            if(nx < 1 || nx > 20 || ny < 1 || ny > 20) continue;
            if(map[cur.x][cur.y] != map[nx][ny]) continue;
            // System.out.println("map_next : " +map[cur.x][cur.y] + " " +map[nx][ny]);
            // System.out.println("next : {" + nx +"," + ny+"}");
            q.add(new Pair(nx, ny));
            cnt++;
        }

        dirNum = dirNum + 1;
        q.add(new Pair(curX, curY));
        // System.out.println("cur(" + dirNum +") : {" + curX +"," + curY+"}");
        // System.out.println("map_cur: " + map[curX][curY]);
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int nx = cur.x + dir[dirNum][0];
            int ny = cur.y + dir[dirNum][1];
            if(nx < 1 || nx > 20 || ny < 1 || ny > 20) continue;
            if(map[cur.x][cur.y] != map[nx][ny]) continue;
            // System.out.println("map_next : " +map[cur.x][cur.y] + " " +map[nx][ny]);
            // System.out.println("next : {" + nx +"," + ny+"}");
            q.add(new Pair(nx, ny));
            cnt++;
        }
        
        // System.out.println("cnt : " + cnt);
        if(cnt + 1 == 5) return true;

        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        if(n < 9){
            bw.append(ans +"\n");
            bw.flush();
            br.close();
            bw.close();
            return;
        }

        int val = -1;
        boolean findAnswer = false;
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            map[x][y] = val;
            val = -1*val;
            // System.out.println("index: " + (i+1));
            if( i > 7){
                for(int j = 0; j < 4; j++){
                    if(count(x, y, 2*j)){
                        ans = i+1;
                        findAnswer = true;
                        break;
                    }
                }
            }

            if(findAnswer) break;
        }
        bw.append(ans + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}