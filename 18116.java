import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static int[] parent = new int[1000001];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        
        Arrays.fill(parent,-1);
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());

            String op = st.nextToken();
            if(op.equals("I")){
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                union(a,b);
            }else{
                int idx = Integer.parseInt(st.nextToken());
                idx = find(idx);
                System.out.println(-1*parent[idx]);
            }
        }

    }

    static void union(int a,int b){
        a = find(a);
        b = find(b);
        // System.out.println("union: " + a +" " + b);
        if(a == b) return;

        if(a < b){
            parent[a] += parent[b];
            parent[b] = a;
        }else{
            parent[b] += parent[a];
            parent[a] = b;
        }
    }

    static int find(int a){
        if(parent[a] < 0){
            return a;
        }else{
            return parent[a] = find(parent[a]);
        }
    }
}