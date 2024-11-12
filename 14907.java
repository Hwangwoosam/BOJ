import java.util.*;
import java.io.*;

class Main{
    static int[] startTime = new int[26];
    static int[] endTime = new int[26];
    static int[] indegree = new int[26];
    
    static ArrayList<Integer>[] adj = new ArrayList[26];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        Arrays.fill(endTime,0);
        Arrays.fill(startTime,0);
        Arrays.fill(indegree,0);
        
        for(int i = 0; i < 26; i++){
            adj[i] = new ArrayList<Integer>();
        }

        while(br.ready()){
            st = new StringTokenizer(br.readLine());
            
            int task = (int)((char)st.nextToken().charAt(0)-'A');
            startTime[task] = Integer.parseInt(st.nextToken());

            if(st.countTokens() == 0) indegree[task] = 0;
            else{
                String after = st.nextToken();
                indegree[task] = after.length();

                for(int i = 0; i < after.length(); i++){
                    int next = (int)((char)after.charAt(i)-'A');
                    adj[next].add(task);
                }
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < 26; i++){
            if(indegree[i] == 0){
                q.add(i);
                endTime[i] = startTime[i];
            }
        }

        while(!q.isEmpty()){
            int cur = q.poll();

            for(int next : adj[cur]){
                endTime[next] = Math.max(endTime[next], endTime[cur] + startTime[next]);
                indegree[next]--;
                if(indegree[next] == 0){
                    q.add(next);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = Math.max(ans,endTime[i]);
        }
        
        bw.append(ans + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}