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

        for(int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b,c));
            graph[b].add(new Pair(a,c));
        }

        Long ans = FindWay();
        bw.append(ans + "\n");
        bw.flush();
    }

    static Long FindWay(){
        Long ret = 0L;
        int maxVal = 0;
        pq.add(new Pair(1,0));

        while(!pq.isEmpty()){
            Pair cur = pq.poll();

            if(visited[cur.idx]) continue;
            visited[cur.idx] = true;
            if(maxVal < cur.val) maxVal = cur.val;
            ret += cur.val;

            // System.out.println(cur.idx + ":" + cur.val);

            for(int i = 0; i < graph[cur.idx].size(); i++){
                Pair next = graph[cur.idx].get(i);

                if(visited[next.idx]) continue;

                pq.add(next);
            }
        }

        return ret-maxVal;
    }

    static class Pair implements Comparable<Pair>{
        int idx;
        int val;

        public Pair(int idx, int val){
            this.idx = idx;
            this.val = val;
        }

        @Override
        public int compareTo(Pair o){
            return this.val - o.val;
        }
    }
}