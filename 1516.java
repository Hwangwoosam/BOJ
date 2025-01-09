import java.util.*;
import java.io.*;

class Main{
    static int n;
    static ArrayList<Integer>[] graph;
    static int[] time,indegree,minTime;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());

        graph = new ArrayList[n+1];
        time = new int[n+1];
        minTime = new int[n+1];
        indegree = new int[n+1];

        for(int i = 0; i <= n; i++) graph[i] = new ArrayList<Integer>();

        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());

            time[i] = Integer.parseInt(st.nextToken());     
            while(true){
                int preCond = Integer.parseInt(st.nextToken());
                
                if(preCond == -1) break;

                graph[preCond].add(i);
                indegree[i]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0) {
                q.add(i);
                minTime[i] = time[i];
            }
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int next : graph[cur]){
                minTime[next] = Math.max(minTime[next],minTime[cur] + time[next]);

                if(--indegree[next] == 0){
                    q.add(next);
                }
            }
        }

        for(int i = 1; i <= n; i++) System.out.println(minTime[i]);
    }
}