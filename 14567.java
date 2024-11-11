import java.util.*;
import java.io.*;

class Main{
    static int n,m;

    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[] dp = new int[n+1];
        boolean[][] list = new boolean[n+1][n+1];
        int[] indegree = new int[n+1];
        Arrays.fill(indegree,0);

        Queue<Integer> q = new LinkedList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a][b] = true;
            indegree[b]++;
        }

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0) q.add(i);
        }

        int pre = 1;
        while(!q.isEmpty()){
            int qSize = q.size();

            for(int i = 0; i < qSize; i++){
                int cur = q.poll();
                dp[cur] = pre;
                for(int j = cur+1; j <= n; j++){
                    if(list[cur][j]){
                        indegree[j]--;
                        if(indegree[j] == 0) q.add(j);
                    }
                }
            }

            pre++;
        }

        for(int i = 1; i<= n; i++){
            bw.append(dp[i] + " ");
        }
        bw.append("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}