import java.util.*;
import java.io.*;

class Main{
    static final long maxVal = Long.MAX_VALUE;
    static int n,m,a,b,k;
    static ArrayList<int[]>[] graph;
    static int[][] t;

    static class Pair implements Comparable<Pair>{
        int cur, k;
        long dist;
        Pair() {}
        Pair(int cur,long dist, int k){
            this.cur = cur;
            this.dist = dist;
            this.k = k;
        }

        @Override
        public int compareTo(Pair o){
            if( dist > o.dist) return 1;
            else if(dist < o.dist) return -1;
            else return Integer.compare(k,o.k);
        }
    }

    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        t = new int[m][101];
        graph = new ArrayList[n+1];
        for(int i = 0; i < n+1; i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            graph[from].add(new int[] {to,i});
            graph[to].add(new int[] {from,i});
            t[i][0] = val;
        }

        k = Integer.parseInt(br.readLine());

        for(int j = 1; j < k+1; j++){
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++) t[i][j] = Integer.parseInt(st.nextToken());
        }

        long ans = dijkstra(a,b);
        bw.append(ans+"\n");
        bw.flush();

        br.close();
        bw.close();
    }

    static long dijkstra(int s,int e){
        long[][] dist = new long[n+1][k+1];
        for(int i = 0; i < n+1; i++ )Arrays.fill(dist[i], maxVal);
        dist[s][0] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(s,0,0));
        while(!pq.isEmpty()){
            Pair pair = pq.poll();

            if(dist[pair.cur][pair.k] < pair.dist) continue;
            if(pair.cur == e) return dist[pair.cur][pair.k];
            
            for(int i = pair.k; i < k+1; i++){
                for(int j = 0; j < graph[pair.cur].size(); j++){
                    int next = graph[pair.cur].get(j)[0];
                    int r = graph[pair.cur].get(j)[1];
                    int tk = t[r][i];
                    if(tk + pair.dist < dist[next][i]){
                        dist[next][i] = tk + pair.dist;
                        pq.add(new Pair(next, tk + pair.dist,i));
                    }
                }
            }
        }
        long d = maxVal;
        for(int i = 0; i < k+1; i++) d = Math.min(d,dist[e][i]);
        return d;
    }
}