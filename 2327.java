import java.util.*;
import java.io.*;

class Main{
    static int h,n;
    static int[] dp;
    static Pair[] p;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        h = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        dp = new int[h+1];
        dp[0] = Integer.MAX_VALUE;
        p = new Pair[n];
        
        // p[0] = new Pair(Integer.MAX_VALUE,Integer.MAX_VALUE);
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int height = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());

            p[i] = new Pair(height,speed);
        }

        for(int i = 0; i < n; i++){
            for(int j = h; j-p[i].height >= 0; j--){
                dp[j] = Math.max(dp[j],Math.min(dp[j-p[i].height],p[i].speed));
            }
        }

        System.out.println(dp[h]);
    }

    static class Pair implements Comparable<Pair>{
        int height;
        int speed;

        Pair(int height,int speed){
            this.height = height;
            this.speed = speed;
        }

        @Override
        public int compareTo(Pair o){
            return this.speed - o.speed;
        }
    }
}
