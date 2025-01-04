import java.util.*;
import java.io.*;

class Main{
    static char[][] map;
    static int[] dx = {1,0,-1,0,1,1,-1,-1,0};
    static int[] dy = {0,1,0,-1,1,-1,1,-1,0};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        map = new char[8][8];

        for(int i = 0; i < 8; i++) {
            map[i] = br.readLine().toCharArray();
        }

        System.out.println(bfs() ? 1 : 0);
        /*
         * 1. 유닛 이동
         * 2. 벽 이동
         */

        
    }

    static boolean bfs(){
        Queue<Pair> q = new LinkedList<>();
        boolean[][] visited;
        
        q.add(new Pair(7,0));
        
        while(!q.isEmpty()){
            int size = q.size();
            visited = new boolean[8][8];

            for(int i = 0; i < size; i++){
                Pair cur = q.poll();
                
                // System.out.println("cur: " + cur.x + " " + cur.y);
                if(cur.x == 0 && cur.y == 7) return true;
                if(map[cur.x][cur.y] == '#') {
                    // System.out.println("cond1");
                    continue;
                }
                for(int j = 0; j < 9; j++){
                    int nx = cur.x + dx[j];
                    int ny = cur.y + dy[j];

                    if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
                    if(visited[nx][ny] || map[nx][ny] == '#') continue;

                    visited[nx][ny] = true;
                    q.add(new Pair(nx,ny));
                }
            }

            wall_move();

            // for(int i = 0; i < 8; i++){
            //     for(int j = 0; j < 8; j++){
            //         System.out.print(map[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            // System.out.println("============");
        }

        return false;
    }

    static void wall_move(){
        for(int i = 7; i >= 0; i--){
            for(int j = 0; j < 8; j++){
                if(map[i][j] == '#'){
                    map[i][j] = '.';

                    if(i+1 <= 7) map[i+1][j] = '#';
                }
            }
        }
    }

    static class Pair implements Comparable<Pair>{
        int x;
        int y;

        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o){
            return this.x - o.x;
        }
    }
}