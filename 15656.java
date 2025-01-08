import java.util.*;
import java.io.*;

class Main{
    static int[] nums;
    static int n,m;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st  = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        nums = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) nums[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(nums);

        getOrder(0,new int[m]);
        System.out.print(sb.toString());
    }

    static void getOrder(int cnt,int[] arr){
        if(cnt == m){
            for(int i = 0; i < m; i++){
                sb.append(arr[i]).append(' ');
            }
            sb.append('\n');
            return;
        }

        for(int i = 0; i < n; i++){
            arr[cnt] = nums[i];
            getOrder(cnt+1,arr);
        }
    }
}
