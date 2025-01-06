import java.util.*;
import java.io.*;

class Main{
    static int n,t,k;
    static int[] d,indegree,dp;
    static ArrayList<Integer>[] graph;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            d = new int[n+1];
            indegree = new int[n+1];
            dp = new int[n+1];
            graph = new ArrayList[n+1];

            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++){
                d[j] = Integer.parseInt(st.nextToken());
                graph[j] = new ArrayList<>();
            }

            for(int j = 0; j < k; j++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                graph[x].add(y);
                indegree[y]++;
            }
        
            int w = Integer.parseInt(br.readLine());
            
            topologicalSort();

            System.out.println(dp[w]);
        }
    }

    static void topologicalSort(){
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.add(i);
                dp[i] = d[i];
            }
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int next : graph[cur]){
                dp[next] = Math.max(dp[next],dp[cur] + d[next]);

                if(--indegree[next] == 0){
                    q.add(next);
                }
            }
        }
    }
}