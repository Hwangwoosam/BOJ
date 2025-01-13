import java.util.*;
import java.io.*;

class Main{
    static int n;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        int[] arr = new int[n+1];
        int[] dp = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());

        List<Integer> list = new ArrayList<>();

        list.add(Integer.MIN_VALUE);

        for(int i = 1; i <= n; i++){
            int num = arr[i];
            int left = 1;
            int right = list.size()-1;

            if(num > list.get(right)) {
                list.add(num);
                dp[i] = list.size()-1;
            }else{
                while(left < right){
                    int mid = (left + right) / 2;
                    if(list.get(mid) >= num) right = mid;
                    else left = mid +1;
                }

                list.set(right,num);
                dp[i] = right;
            }
        }
        int length = list.size()-1;
        System.out.println(length);
        Stack<Integer> stack = new Stack<>();
        for(int i = n; i >= 1; i--) {
            if(dp[i] == length) {
                stack.push(arr[i]);
                length--;
            }
        }

        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
}