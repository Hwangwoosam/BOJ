import java.util.*;
import java.io.*;

class Main{
    static int[] parent;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int idx = 1;

        StringBuilder sb = new StringBuilder();

        while(true){
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if(n == 0 && m == 0) break;
            
            parent = new int[n+1];
            
            for(int i = 0; i <= n; i++) parent[i] = i;
            
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                union(Math.min(a,b),Math.max(a,b));
            }

            Set<Integer> s = new HashSet<>();
            for(int i = 1; i <= n; i++){
                int p = find(i);
                if(p > 0){
                    s.add(p);
                }
            }
            
            sb.append("Case " + idx + ": ");
            int sSize = s.size();
            if(sSize == 0) sb.append("No trees.\n");
            else if(sSize == 1) sb.append("There is one tree.\n");
            else sb.append("A forest of " + sSize+" trees.\n");

            idx++;
        }

        System.out.print(sb.toString());
    }

    static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a,int b){
        a = find(a);
        b = find(b);
        
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (a == b) {
            parent[a] = 0;
        }else{
            parent[b] = a;
        }
    
    }

}