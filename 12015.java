import java.io.*;
import java.util.*;

class Main{
    static int[] nums;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        nums = new int[n+1];
        int[] dp = new int[n+1];
        Arrays.fill(dp,0);

        for(int i = 1; i <= n; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }

        dp[1] = nums[1];
        int lastIdx = 1;

        for(int i = 2; i <= n; i++){
            int target = nums[i];

            if(dp[lastIdx] < target){
                lastIdx++;
                dp[lastIdx] = target;
            }else{
                int left = 0;
                int right = lastIdx;
                while(left < right){
                    int mid = (left + right)/2;

                    if(dp[mid] < target) left = mid + 1;
                    else right = mid;
                }
                dp[left] = target;
            }
        }

        bw.append(lastIdx + "\n");
        bw.flush();
    }
}