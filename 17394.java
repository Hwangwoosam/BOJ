import java.util.*;
import java.io.*;

class Main{
    static int dir[] = {3,2,1,-1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        
        boolean[] prime = new boolean[1000001];
        boolean[] visited = new boolean[1000001];
        prime[0] = true;
        prime[1] = true;

        for(int i = 2; i*i < 1000001; i++){
            if(prime[i]) continue;
            for(int j = i*i; j < 1000001; j +=i){
                prime[j] = true;
            }
        }
        
        int[] nums = new int[1000001];

        for(int i = 0; i < t; i++){
            // System.out.println("t: " + t + ":" + i);
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            Arrays.fill(nums,1000001);
            Arrays.fill(visited,false);
            Queue<Integer> q = new LinkedList<>();
            q.add(n);
            nums[n] = 0;
            visited[n] = true;
            boolean findAns = false;
            while(!q.isEmpty()){
                int cur = q.poll();

                if(cur >= a && cur <= b && !prime[cur]){
                    findAns = true;
                    bw.append(nums[cur] + "\n");
                    bw.flush();
                    break;
                }


                for(int j = 0; j < 4; j++){
                    int nx = cur;
                    if(j <= 1) nx /= dir[j];
                    else nx += dir[j];

                    if(nx < 0 || nx > 1000000) continue;
                    if(visited[nx]) continue;
                    if(nums[nx] <= nums[cur] + 1) continue;

                    nums[nx] = nums[cur]+1;
                    visited[nx] = true;
                    q.add(nx); 
                }
            }

            if(!findAns) {
                bw.append("-1\n");
                bw.flush();
            }
        }
    }
}