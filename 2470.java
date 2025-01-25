import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());


        int [] num = new int[n];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) num[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(num);
        
        int left = 0, right = n-1;
        long min = Long.MAX_VALUE;
        int mL = 0, mR = 0;
        while(left < right){
            long sum = num[left] + num[right];

            if(min > Math.abs(sum)){
                min = Math.abs(sum);
                mL = left;
                mR = right;
            }

            if(sum >= 0) right--;
            else left++;
        }
        System.out.println(num[mL]+" " +num[mR]);
    }
}