import java.util.*;
import java.io.*;

class Main{
    static class Pair implements Comparable<Pair>{
        int dest;
        int val;

        public Pair(int dest,int val){
            this.dest = dest;
            this.val = val;
        }

        @Override
        public int compareTo(Pair o){
            return this.val - o.val;
        }
    }

    static int n,m,s,e;
    static ArrayList<Pair>[] graph;
    static int[] dist;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        dist = new int[n+1];
        Arrays.fill(dist,100000000);

        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<Pair>();
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b,c));
            graph[b].add(new Pair(a,c));    
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        dijkstra(s,e);

        bw.append(dist[e] + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

    static void dijkstra(int s,int e){
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        dist[s] = 0;
        pq.add(new Pair(s,0));

        while(!pq.isEmpty()){
            Pair cur = pq.poll();

            if(dist[cur.dest] < cur.val) continue;

            int nextSize = graph[cur.dest].size();
            for(int i = 0; i < nextSize; i++){
                int nextIdx = graph[cur.dest].get(i).dest;
                int nextVal = graph[cur.dest].get(i).val;

                if(dist[nextIdx] > dist[cur.dest]+nextVal) {
                    dist[nextIdx] = dist[cur.dest]+nextVal;
                    pq.add(new Pair(nextIdx,dist[nextIdx]));
                }
            }
        }
    }
}