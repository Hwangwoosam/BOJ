import java.io.*;
import java.util.*;

class Main{
    static int n,m;
    static int[] parent;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        Arrays.fill(parent,-1);

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            if(cmd == 0){
                union(a,b);
            }else{
                a = Find(a);
                b = Find(b);
                if(a == b) bw.append("yes\n");
                else bw.append("no\n");
                bw.flush();
            }
        }
    }

    static int Find(int a){
        if(parent[a] < 0) return a;
        return parent[a] = Find(parent[a]);
    }

    static void union(int a,int b){
        a = Find(a);
        b = Find(b);

        if(a == b) return;

        parent[a] += parent[b];
        parent[b] = a;
    }
}