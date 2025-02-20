import java.util.*;
import java.io.*;

class Main{
    static int n,m,t;
    static int[] height;
    static ArrayList<Integer>[] graph;
    static int[][] island;

    static int findLowestInk(int idx,int k){
        if(island[idx][k] != Integer.MAX_VALUE) return island[idx][k];
        else if(k == 0) return island[idx][k] = height[idx-1];

        for(int next : graph[idx]){
            island[idx][k] = Math.min(island[idx][k],findLowestInk(next,k-1));
        }        

        return island[idx][k];
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        height = new int[n];
        graph = new ArrayList[n+1];
        island = new int[n+1][501];
        
        for(int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
            Arrays.fill(island[i],Integer.MAX_VALUE);
        }

        st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < n; i++) height[i] = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int to = Integer.parseInt(st.nextToken());
            int from = Integer.parseInt(st.nextToken());

            graph[to].add(from);
            graph[from].add(to);
        }

        t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < t; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            
            int ans = findLowestInk(start,k);
            sb.append(ans == Integer.MAX_VALUE ? -1 : ans);
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }
}