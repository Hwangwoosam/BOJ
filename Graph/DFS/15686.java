import java.util.*;
import java.io.*;

public class Main{

    static int n,m,answer;
    static int[][] map;
    static boolean selected[];
    static ArrayList<Pair> house_pos;
    static ArrayList<Pair> chick_pos;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
        String[] size = br.readLine().split(" ");   
        n = Integer.parseInt(size[0]); 
        m = Integer.parseInt(size[1]);

        map = new int[n][n];
        selected = new boolean[13];
        house_pos = new ArrayList<>();
        chick_pos = new ArrayList<>();

        for(int i = 0; i < n; i++){
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for(int j = 0; j < n; j++){
                if(map[i][j] == 1){
                    house_pos.add(new Pair(i, j));
                }else if(map[i][j] == 2){
                    chick_pos.add(new Pair(i, j));
                }
            }
        }

        answer = Integer.MAX_VALUE;
        dfs(0,0);
        bw.write(String.valueOf(answer));
        bw.write("\n");
        bw.flush();
    }

    static void dfs(int idx, int m_cnt){
        if(m_cnt == m){
            int dist_sum = 0;
            for(int i = 0; i < house_pos.size(); i++){
                int dist_min = Integer.MAX_VALUE;
                for(int j = 0; j < chick_pos.size(); j++){
                    if(selected[j]){
                        dist_min = Math.min(dist_min,Math.abs(house_pos.get(i).x-chick_pos.get(j).x) + Math.abs(house_pos.get(i).y-chick_pos.get(j).y));
                    }
                }
                dist_sum += dist_min;
            }
            answer = Math.min(answer,dist_sum);
            return;
        }

        for(int i = idx; i < chick_pos.size(); i++){
            if(!selected[i]){
                selected[i] = true;
                dfs(i,m_cnt+1);
                selected[i] = false;
            }
        }
    }
}

class Pair{
    int x;
    int y;

    Pair(int x,int y){
        this.x = x;
        this.y = y;
    }
}