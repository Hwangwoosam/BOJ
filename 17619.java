import java.util.*;
import java.io.*;

class Main{
    static int n,q;
    static int[] parent;
    static Line[] trunck;
    static int[] rank;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        parent = new int[n+1]; 
        rank = new int[n+1];
        trunck = new Line[n+1];
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            trunck[i] = new Line(a,b,c);
        }

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(parent[i] == parent[j]) continue;
                if(trunck[i].e < trunck[j].s || trunck[i].s > trunck[j].e) continue;
                if(trunck[i].y == trunck[j].y) continue;

                union(i,j);
            }
        }

        for(int i = 0; i < q; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(parent[a] == parent[b]) bw.append("1\n");
            else bw.append("0\n");
        }

        bw.flush();
    }

    static int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    static void union(int a,int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(rank[a] < rank[b]) parent[b] = a;
        else parent[a] = b;

        if(rank[a] == rank[b]) rank[a]++;
    }

    static class Line{
        int s;
        int e;
        int y;
        public Line(int s,int e,int y){
            this.s = s;
            this.e = e;
            this.y = y;
        }
    }
}