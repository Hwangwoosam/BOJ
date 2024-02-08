import java.io.*;
import java.util.*;

class Main{

    static int parent[];

    static class Node implements Comparable<Node>{
        int from;
        int to;
        int value;

        public Node(int from,int to, int value){
            this.from = from;
            this.to = to;
            this.value = value;
        }
        
        public int compareTo(Node o){
            return this.value - o.value;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        Queue<Node> pq = new PriorityQueue<>();

        parent = new int[n+1];
        parent[0] = 0;

        for(int i = 1; i <= n; i++){
            int w = Integer.parseInt(br.readLine());
            parent[i] = i;
            pq.add(new Node(0,i,w));
        }

        StringTokenizer st;
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++){
                int w = Integer.parseInt(st.nextToken());
                if(i==j) continue;
                pq.add(new Node(i,j,w));
            }
        }

        int pqSize = pq.size();
        long total = 0;
        int cnt = 0;
        for(int i = 0; i < pqSize; i++){
            Node node = pq.poll();
            int from = find(node.from);
            int to = find(node.to);
            if(!isSameParent(to, from)){
                total += node.value;
                union(node.from, node.to);
                if(++cnt == n){
                    bw.write(total + "\n");
                    bw.flush();
                    break;
                }
            }
        }
        br.close();
        bw.close();
    }

    public static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x,int y){
        x = find(x);
        y = find(y);
        if(x != y){
            parent[y] = x;
        }
    }

    public static boolean isSameParent(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y) return true;
        return false;
    }
}