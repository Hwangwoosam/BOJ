import java.util.*;
import java.io.*;

class Main{
    static int[][] map = new int[9][9];
    static Queue<Pair> q = new LinkedList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for(int i = 0; i < 9; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 9; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 0) {
                    q.add(new Pair(i,j));
                }
            }
        }

        findWay(new LinkedList<>(q));

    }

    static void findWay(Queue<Pair> q){
        if(q.isEmpty()){
            print();
            System.exit(0);
        }

        Pair cur = q.poll();

        for(int i = 1; i <= 9; i++){
            if(isPossible(cur.x,cur.y,i)){
                map[cur.x][cur.y] = i;
                findWay(new LinkedList<>(q));
                map[cur.x][cur.y] = 0;
            }
        }
    }

    static boolean isPossible(int x,int y, int val){
        int stX = 3*(x/3), stY = 3*(y/3);
        // System.out.println(stX + " " + stY);
        for(int i = stX; i < stX+3; i++){
            for(int j = stY; j < stY+3; j++){
                if(map[i][j] == val) return false;
            }
        }
        
        for(int i = 0; i < 9; i++){
            if(i == y) continue;
            if(map[x][i] == val) return false;
        }

        for(int i = 0; i < 9; i++){
            if(i == x) continue;
            if(map[i][y] == val) return false;
        }

        return true;
    }

    static void print(){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
        // System.out.println("--------------------");
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
            return o.x - this.x;
        }
    }
}