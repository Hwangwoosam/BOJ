import java.io.*;
import java.util.*;

class Main{
    static int[] dp;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        StringTokenizer st  = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }

        dp = new int[n+1];

        int len = 0;
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > dp[len]) dp[++len] = nums[i];
            else{
                idx = binarySearch(0,len,nums[i]);
                dp[idx] = nums[i];
            }
        }

        bw.append(len+"\n");
        bw.flush();
    }
    
    static int binarySearch(int left,int right, int target){
        int mid;
        while(left < right){
            mid = (left+right)/2;
            if(dp[mid] < target){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        return right;
    }
}