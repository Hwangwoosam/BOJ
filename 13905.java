import java.util.*;
import java.io.*;

class Main{
    static int n,m,s,e;
    static Pair[] graph;
    static int[] parent;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        graph = new Pair[m];
        for(int i = 0; i <=n; i++) parent[i] = i;
        
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[i] = new Pair(a,b,c);
        }

        Arrays.sort(graph);

        int ans = 0;
        for(int i = 0; i < m; i++){
            union(graph[i].s,graph[i].e);
            ans = graph[i].val;
            if(find(s) == find(e)) break;
        }

        if(parent[s] != parent[e]) ans = 0;
        bw.append(ans + "\n");
        bw.flush();
    }
    static void union(int a,int b){
        a = find(a);
        b = find(b);

        if(a == b) return;
        parent[b] = a;
    }

    static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }


    static class Pair implements Comparable<Pair>{
        int s;
        int e;
        int val;
        public Pair(int s,int e,int val){
            this.s = s;
            this.e = e;
            this.val = val;
        }

        @Override
        public int compareTo(Pair o){
            return (this.val - o.val) * -1;
        }
    }
}