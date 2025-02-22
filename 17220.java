import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static ArrayList<Integer>[] graph;
    static List<Integer> header = new ArrayList<>();
    static int[] indegree;
    static boolean[] check;
    static int cnt;
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        indegree = new int[n];
        check = new boolean[n];
        Arrays.fill(indegree,0);

        graph = new ArrayList[n];
        for(int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = String.valueOf(st.nextToken()).charAt(0) - 'A';
            int to = String.valueOf(st.nextToken()).charAt(0) - 'A';
            
            graph[from].add(to);
            indegree[to]++;
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                header.add(i);
            }
        }

        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; i++){
            int a = String.valueOf(st.nextToken()).charAt(0) - 'A';

            graph[a].clear();
            if(!header.contains(a)){
                for(int j = 0; j < n; j++){
                    graph[j].remove(Integer.valueOf(a));
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                dfs(i);               
            }
        }
        
        System.out.println(cnt);
    }

    static void dfs(int idx){
        check[idx] = true;
        for(int i = 0; i < graph[idx].size(); i++){
            if(!check[graph[idx].get(i)]){
                dfs(graph[idx].get(i));
                cnt++;
            }
        }
    }
}