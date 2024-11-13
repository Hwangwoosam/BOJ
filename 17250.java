import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] parent;
    static int[] totalSum;
    static int[] planetNum;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        planetNum = new int[n+1];
        totalSum = new int[n+1];

        Arrays.fill(parent,-1);

        for(int i = 1; i <= n ; i++){
            planetNum[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            Union(a,b);
            int idx = Find(a);
            bw.append(planetNum[idx] + "\n");
            bw.flush();
        }
    }

    static int Find(int a){
        if(parent[a] < 0) return a;
        return parent[a] = Find(parent[a]);
    }

    static void Union(int a,int b){
        a = Find(a);
        b = Find(b);

        if(a == b) return;
        parent[a] += parent[b];
        planetNum[a] += planetNum[b];
        parent[b] = a;
    }
}