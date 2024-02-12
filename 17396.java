import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static boolean sight[];
    static ArrayList<Node>[] list;
    static long dist[];

    static class Node implements Comparable<Node>{
        int node;
        long cost;

        public Node(int node,long cost){
            this.node = node;
            this.cost = cost;
        }

        public int compareTo(Node n){
            if(this.cost - n.cost > 0) return 1;
            return -1;
        }
    }

    
    public static void dijkstra(){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[n];
        pq.offer(new Node(0,0));

        while(!pq.isEmpty()){
            Node cur = pq.poll();

            if(visited[cur.node]) continue;
            visited[cur.node] = true;

            int listSize = list[cur.node].size();
            for(int i = 0; i < listSize; i++){
                Node next = list[cur.node].get(i);
                if(next.node != n-1 && sight[next.node]) continue;
                if(dist[next.node] > dist[cur.node] + next.cost){
                    dist[next.node] = dist[cur.node] + next.cost;
                    pq.offer(new Node(next.node,dist[next.node]));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        sight = new boolean[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            if(Long.parseLong(st.nextToken()) == 1){
                sight[i] = true;
            }else{
                sight[i] = false;
            }
        }

        list = new ArrayList[n];
        for(int i = 0; i < n; i++){
            list[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,t));
            list[b].add(new Node(a,t));
        }

        dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        dijkstra();

        if(dist[n-1] == Long.MAX_VALUE){
            bw.append("-1");
            // System.out.println("-1");
        }else{
            // System.out.println(dist[n-1]);
            bw.append(Long.toString(dist[n-1]));
        }
        
        bw.flush();
        br.close();
        bw.close();
    }
}