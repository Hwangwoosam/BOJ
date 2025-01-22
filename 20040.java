import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] parent;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i = 0; i <= n; i++) parent[i] = i;

        int idx = 0; 
        for(int i = 1; i <= m; i++){
            st = new StringTokenizer(br.readLine());
            int a = find(Integer.parseInt(st.nextToken()));
            int b = find(Integer.parseInt(st.nextToken()));

            if(a == b) {
                idx = i;
                break;
            }else union(a,b);
        }

        System.out.println(idx);
    }

    static int find(int x){
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    static void union(int a, int b){
        a = find(a);
        b = find(b);

        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        
        parent[b] = a;
    }
}