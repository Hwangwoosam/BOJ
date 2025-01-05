import java.util.*;
import java.io.*;

class Main{
    static int[][] map;
    static boolean[] visited;
    static int res = Integer.MAX_VALUE;
    static int n;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        
        map = new int[n][n];
        visited = new boolean[n];

        StringTokenizer st;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }

        dfs(0);
        System.out.println(res);
    }

    static void dfs(int idx){
        if(idx == n){
            getAnser();
            return;
        }
        
        visited[idx] = true;
        dfs(idx+1);
        visited[idx] = false;
        dfs(idx+1);
    }
    

    static void getAnser(){
        int start = 0, link = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(visited[i] && visited[j]){
                    start += map[i][j] + map[j][i];
                }else if(!visited[i] && ! visited[j]){
                    link += map[i][j] + map[j][i];
                }
            }
        }

        int diff = Math.abs(start-link);
        res = Math.min(res,diff);
    }
}