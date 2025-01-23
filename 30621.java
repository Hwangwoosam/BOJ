import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int[] t,b;
    static long[] c;
    static int[] dp;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        t = new int[n+1];
        b = new int[n+1];
        c = new long[n+1];
        dp = new int[n+1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) t[i] = Integer.parseInt(st.nextToken());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) b[i] = Integer.parseInt(st.nextToken());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) c[i] = Long.parseLong(st.nextToken());

        for(int i = 0; i < n; i++){
            dp[i] = Math.max(dp[i],c[i]);
            int idx = i;
            while(idx < n){
                idx = findNext();
            }
        }

    }

    static findNext(int target){
        int left = 0, right = n-1;
        while(left < right){
            int mid = (left+right)/2;

            if(target > t[mid]-b[mid]) right--;
            else if(target < t[mid] - b[mid]) left++;
            else return mid;
        }

        return n;
    }
}