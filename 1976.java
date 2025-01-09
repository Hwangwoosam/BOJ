import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] parent;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        parent = new int[n+1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        StringTokenizer st;
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++){
                int val = Integer.parseInt(st.nextToken());

                if(val == 1) {
                    union(i, j);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        boolean possible = true;

        for (int i = 1; i < m; i++) {
            int next = Integer.parseInt(st.nextToken());
            if (find(start) != find(next)) {
                possible = false;
                break;
            }
        }

        System.out.println(possible ? "YES" : "NO");

    }

    static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
        }
    }
}