import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;

class Main{
    public static int[] bridge;
    static int a,b,n,m;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        a = Integer.parseInt(inp[0]);
        b = Integer.parseInt(inp[1]);
        n = Integer.parseInt(inp[2]);
        m = Integer.parseInt(inp[3]);
        int[] dir = {1,-1,a,b,-a,-b};

        bridge = new int[100001];
        Arrays.fill(bridge,Integer.MAX_VALUE);
        Queue<Integer> q = new LinkedList<>();
        bridge[n] = 0;
        
        q.offer(n);

        int answer = 0;
        while(!q.isEmpty()){
            int cur = q.poll();

            if(cur == m) break;

            for(int i = 0; i < 6; i++){
                int next = cur + dir[i];
                if(next < 0 || next > 100000 || bridge[next] <= bridge[cur] + 1) continue;
                bridge[next] = bridge[cur] + 1;
                q.offer(next);
            }

            for(int i= 2; i <4; i++){
                int next = cur*dir[i];
                if(next < 0 || next > 100000 || bridge[next] < bridge[cur] + 1) continue;
                bridge[next] = bridge[cur] + 1;
                q.offer(next);
            }   
        }
        System.out.println(bridge[m]);
    }
}