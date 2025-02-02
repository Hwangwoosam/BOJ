import java.util.*;
import java.io.*;

class Main{
    static int n,s,e;
    static ArrayList<Node> graph[];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        for(int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < n-1; i++){
            st = new StringTokenizer(br.readLine());

            int to = Integer.parseInt(st.nextToken());
            int from = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            graph[to].add(new Node(from,dist));
            graph[from].add(new Node(to,dist));
        }

        int res = dijkstra();
        System.out.println(res);
    }

    static int dijkstra(){
        PriorityQueue<Ways> pq = new PriorityQueue<>();
        pq.add(new Ways(s,0,0));

        boolean[] visited = new boolean[n+1];
        visited[s] = true;

        while(!pq.isEmpty()){
            Ways cur = pq.poll();
            
            if(cur.idx == e) return cur.totalDist - cur.maxDist;

            int pathCnt = graph[cur.idx].size();
            for(int i = 0; i < pathCnt; i++){
                Node next = graph[cur.idx].get(i);
                if(visited[next.dest]) continue;

                visited[next.dest] = true;
                pq.add(new Ways(next.dest,cur.totalDist + next.dist,Math.max(cur.maxDist,next.dist)));
            }
        }
        return 0;
    }

    static class Node{
        int dest;
        int dist;

        Node(int dest,int dist){
            this.dest = dest;
            this.dist = dist;
        }
    }

    static class Ways implements Comparable<Ways>{
        int idx;
        int totalDist;
        int maxDist;

        Ways(int idx,int totalDist, int maxDist){
            this.idx = idx;
            this.totalDist = totalDist;
            this.maxDist = maxDist;
        }

        @Override
        public int compareTo(Ways o) {
            return this.totalDist - o.totalDist;
        }
    }
}