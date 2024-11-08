import java.util.*;
import java.io.*;

class Main{
    static int n;
    static ArrayList<Integer>[] graph;
    static int[] visited;
    static String ans = "NO CYCLE";
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        graph = new ArrayList[n+1];
        visited = new int[n+1];

        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<Integer>();
        }

        for(int i = 1; i< n; i++){
            int m = Integer.parseInt(br.readLine());

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                graph[i].add(Integer.parseInt(st.nextToken()));
            }
        }

        findCycle(1);
        bw.append(ans + "\n");
        bw.flush();
    }

    static void findCycle(int cur){
        if(visited[cur] == -1){
            ans = "CYCLE";
            return;
        }

        visited[cur] = -1;

        for(int next : graph[cur]){
            if(visited[next] != 1){
                findCycle(next);
            }
        }

        visited[cur] = 1;
    }
}