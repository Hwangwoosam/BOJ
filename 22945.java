import java.util.*;
import java.io.*;

class Main {
    static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) nums[i] = Integer.parseInt(st.nextToken());

        int left = 0, right = n - 1;
        int res = 0;
        while(left < right) {
            int curVal = (right - left - 1) * Math.min(nums[left], nums[right]);
            res = Math.max(res, curVal);
            
            if(nums[left] < nums[right]) {
                left++;
            } else {
                right--;
            }
        }

        System.out.println(res);
    }
}
