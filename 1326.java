import java.util.*;
import java.io.*;

class Main{
    static int a,b,n;
    static int[] bridge;
    static int[] dist;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        bridge = new int[n+1];
        dist = new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) bridge[i] = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        bfs(a,b);
    }

    static void bfs(int start,int end){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dist[start] = 0;

        if(start == end){
            System.out.println(0);
            return;
        }

        while(!q.isEmpty()){
            int cur = q.poll();
            int val = bridge[cur];

            int next = cur;
            while(true){
                next += val;
                if(next > n) break;
                if(dist[next] < dist[cur]+1) continue;
            
                if(next == end){
                    System.out.println(dist[cur]+1);
                    return;
                }

                dist[next] = dist[cur] + 1;
                q.add(next);
            }

            next = cur;
            while(true){
                next -= val;
                if(next <= 0) break;
                if(dist[next] < dist[cur]+1) continue;

                if(next == end){
                    System.out.println(dist[cur]+1);
                    return;
                }

                dist[next] = dist[cur] + 1;
                q.add(next);
            }
        }
        
        System.out.println(-1);
    }
}