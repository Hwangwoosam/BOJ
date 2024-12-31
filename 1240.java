import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static ArrayList<Pair>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
    
        graph = new ArrayList[n+1];
        for(int i = 0; i <= n; i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < n-1; i ++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());

            graph[from].add(new Pair(to,val));
            graph[to].add(new Pair(from,val));
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());   
            visited = new boolean[n + 1];
            sb.append(dfs(start,end,0)).append("\n");
        }

        bw.append(sb.toString());
        bw.flush();
    }
    
    static class Pair{
        int to;
        int val;

        Pair(int to,int val){
            this.to = to;
            this.val = val;
        }
    }

    static int dfs(int cur, int end, int dist){
        if(cur == end) return dist;

        visited[cur] = true;

        for (Pair next : graph[cur]) {
            if (!visited[next.to]) {
                int result = dfs(next.to, end, dist + next.val);
                if (result != -1) {
                    return result;
                }
            }
        }

        visited[cur] = false;
        return -1;
    }
}