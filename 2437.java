import java.io.*;
import java.util.*;

class Main{
    static int[] nums;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        nums = new int[n];
        for(int i = 0; i < n; i++) nums[i] =  Integer.parseInt(st.nextToken());

        Arrays.sort(nums);
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > sum+1) break;
            sum += nums[i];
        }

        System.out.println(sum+1);
    }
}