import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] indegree;
    static ArrayList<Integer>[] adj;
    static PriorityQueue<String>[] child;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        indegree = new int[n];
        Arrays.fill(indegree,0);

        HashMap<String,Integer> name2Idx = new HashMap<>();
        HashMap<Integer,String> idx2Name = new HashMap<>(); 
        PriorityQueue<String> pq = new PriorityQueue<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        adj = new ArrayList[n];
        child = new PriorityQueue[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
            child[i] = new PriorityQueue<>();
        }

        int idx = 0;
        while(st.countTokens() > 0){
            String name = st.nextToken();
            pq.add(name);
            name2Idx.put(name,idx);
            idx2Name.put(idx,name);
            idx++;
        }

        m = Integer.parseInt(br.readLine());

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            Integer c = name2Idx.get(st.nextToken());
            Integer p = name2Idx.get(st.nextToken());

            adj[p].add(c);
            indegree[c]++;
        }

        Queue<Integer> q = new LinkedList<>();
        PriorityQueue<String> ancestor = new PriorityQueue<>();
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.add(i);
                ancestor.add(idx2Name.get(i));
            }
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int next : adj[cur]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.add(next);
                    child[cur].add(idx2Name.get(next));
                }
            }
        }
        
        boolean[] visited = new boolean[n];
        StringBuilder sb = new StringBuilder();
        sb.append(ancestor.size()).append("\n");
        for(String name : ancestor){
            sb.append(name).append(" ");
        }
        sb.append("\n");
        while(!pq.isEmpty()){
            String curName = pq.poll();
            idx = name2Idx.get(curName);
            if(visited[idx]) continue;

            sb.append(curName).append(" ");
            sb.append(child[idx].size()).append(" ");
            while(!child[idx].isEmpty()){
                String curChild = child[idx].poll();    
                sb.append(curChild).append(" ");
            }
            sb.append("\n");
            visited[idx] = true;
        }

        bw.append(sb.toString());
        bw.flush();
        
    }
}