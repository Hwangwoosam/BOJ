import java.util.*;
import java.io.*;

class Main{
    static int[] height;
    static int[] dp;
    static ArrayList<Integer>[] graph ;
    static int ans = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        dp = new int[n+1];
        height = new int[n+1]; 
        graph = new ArrayList[n+1];

        Arrays.fill(dp,-1);

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            height[i] = Integer.parseInt(st.nextToken());
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            if(height[from] > height[to]){
                if(!graph[to].contains(from)) {
                    graph[to].add(from);
                }
            }else if(height[from] < height[to]){
                if(!graph[from].contains(to)){
                    graph[from].add(to);
                }
            }
        }   

        for(int i = 1; i <= n; i++){
            sb.append(findWay(i)).append("\n");
        }

        bw.append(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }

    public static int findWay(int cur){
        if(dp[cur] != -1) return dp[cur];
            
        int nextSize = graph[cur].size();

        int ret = 1;
        for(int i = 0; i < nextSize; i++){
            int next = graph[cur].get(i);
            ret = Math.max(ret,findWay(next)+1);
        }
        
        dp[cur] = ret;

        return ret;
    }
}