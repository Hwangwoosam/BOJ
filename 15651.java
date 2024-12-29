import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] arr;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[m];

        dfs(0);

        bw.flush();
    }

    static void dfs(int depth) throws Exception{
        if(depth == m){
            for(int i = 0; i < m; i++){
                bw.append(arr[i] + " ");
            }
            bw.append("\n");
            return;
        }        

        for(int i = 1; i <= n; i++){
            arr[depth] = i;
            dfs(depth+1);
        }
    }
}