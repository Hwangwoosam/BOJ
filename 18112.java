import java.util.*;
import java.io.*;

class Main{
    static final int limit = 1 << 10;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int s = Integer.parseInt(br.readLine(),2);
        int e = Integer.parseInt(br.readLine(),2);

        if(s == e) {
            System.out.println(0);
            return;
        }

        boolean[] check = new boolean[limit];
        Queue<int[]> q = new ArrayDeque<>();
        check[s] = true;
        q.add(new int[] {s,0});

        while(!q.isEmpty()){
            int[] cur = q.poll();

            if(cur[0] == e){
                System.out.println(cur[1]);
                return;
            }

            for(int next : bfs(cur[0])){
                if(check[next]) continue;
                check[next] = true;
                q.add(new int[] {next,cur[1] + 1});
            }
        }
    }

    static List<Integer> bfs(int n){
        List<Integer> nexts = new ArrayList<>();
        if(n+1 < limit) nexts.add(n+1);
        if(n != 0){
            nexts.add(n-1);

            int bit = 0;
            int msd = Integer.highestOneBit(n);
            while((1<< bit) != msd){
                int tmp = n^(1<<bit++);
                if(tmp < limit) nexts.add(tmp);
            }
        }

        return nexts;
    }
}