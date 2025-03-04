import java.util.*;
import java.io.*;

class Main{
    static int n,b;
    static int[] nums;
    static int[] dp = new int[200001];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        nums = new int[n];

        st = new StringTokenizer(br.readLine());
        int bIdx = 0;
        for(int i = 0; i < n; i++){
            nums[i] = Integer.parseInt(st.nextToken());
            if(nums[i] == b){
                bIdx = i;
            }
        }

        int cnt = 1;
        int ans = 0;

        for(int i = bIdx; i < n; i++){
            if(nums[i] > b){
                cnt++;
            }else{
                cnt--;
            }

            dp[100000+cnt] += 1;
        }

        cnt = -1;
        for(int i = bIdx; i >= 0; i--){
            if(nums[i] > b){
                cnt--;
            }else{
                cnt++;
            }

            ans += dp[100000+ cnt];
        }

        System.out.println(ans);
    }
}