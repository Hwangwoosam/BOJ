import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static boolean found = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        
        for (int i = 0; i < N; i++) {
            visited = new boolean[N];
            dfs(i, 1);
            if (found) break;
        }
        
        System.out.println(found ? 1 : 0);
    }
    
    static void dfs(int node, int depth) {
        if (depth == 5) {
            found = true;
            return;
        }
        
        visited[node] = true;
        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next, depth + 1);
            }
            if (found) return;
        }
        visited[node] = false;
    }
}