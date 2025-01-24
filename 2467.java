import java.util.*;
import java.io.*;

class Main{
    static int n;
    static Long [] num;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        num = new Long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) num[i] = Long.parseLong(st.nextToken());

        int left = 0, right = n-1;
        long min = Long.MAX_VALUE;
        int minL = 0, minR = 0;
        while(left < right){
            long sum = num[left] + num[right];
            if(min > Math.abs(sum)) {
                min = Math.abs(sum);
                minL = left;
                minR = right;
            }
            
            if( sum >= 0) right--;
            else left++;
        }

        System.out.println(num[minL] + " " + num[minR]);
    }
}