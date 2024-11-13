import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static ArrayList<Pair>[] graph;
    static boolean[] visited;
    static PriorityQueue<Pair> pq;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        visited = new boolean[n+1];
        pq = new PriorityQueue<>();

        for(int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            visited[i] = false;
        }
        Long total = 0L;
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b,c));
            graph[b].add(new Pair(a,c));
            total += c;
        }

        Long ans = findDist();
        for(int i = 1; i <=n; i++){
            if(!visited[i]){
                ans = -1L;
                break;
            }
        }

        if(ans != -1) ans = total-ans;
        

        bw.append(ans + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    static Long findDist(){
        Long ret = 0L;
        pq.add(new Pair(1,0));

        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            
            if(visited[cur.idx]) continue;
            visited[cur.idx] = true;
            ret += cur.val;

            for(int i = 0; i < graph[cur.idx].size(); i++){
                Pair next = graph[cur.idx].get(i);

                if(visited[next.idx]) continue;

                pq.add(next);
            }
        }

        return ret;
    }

    static class Pair implements Comparable<Pair>{
        int idx;
        int val;
        
        Pair(int idx,int val){
            this.idx = idx;
            this.val = val;    
        }

        @Override
        public int compareTo(Pair o){
            return this.val - o.val;
        }
    }
}