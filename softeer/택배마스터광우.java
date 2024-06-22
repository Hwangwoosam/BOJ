import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static int rail[];
    static int matrix[];
    static boolean visited[];
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String[] inp = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        m = Integer.parseInt(inp[1]);
        k = Integer.parseInt(inp[2]);
        rail = new int[n];
        visited = new boolean[n];
        matrix = new int[n];

        inp = br.readLine().split(" ");
        
        for(int i = 0; i < n; i++){
            rail[i] = Integer.parseInt(inp[i]);
        }

        DFS(0);

        bw.append(answer + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

    public static void DFS(int cnt){
        if(cnt == n){
            int idx = 0, sum = 0;

            for(int i = 0; i < k; i++){
                int temp = 0;
                while(temp + matrix[idx] <= m){
                    temp += matrix[idx];
                    idx = (idx+1)%n;
                }
                sum += temp;
            }
            if(answer > sum) answer = sum;
            return;
        }        

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;

            visited[i] = true;
            matrix[cnt] = rail[i]; 
            DFS(cnt+1);
            visited[i] = false;
        }
    }
}