import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        int[] height = new int[n];
        int[] near = new int[n];
        int[] cnt = new int[n];

        for(int i = 0; i < n; i++){
            height[i] = Integer.parseInt(st.nextToken());
            near[i] = -100000;
        }

        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < n; i++){
            while(!stack.isEmpty() && height[stack.peek()] <= height[i]){
                stack.pop();
            }
            cnt[i] = stack.size();
            if(cnt[i] > 0) near[i] = stack.peek();
            stack.push(i);
        }

        stack = new Stack<>();
        for(int i = n-1; i >= 0; i--){
            while(!stack.isEmpty() && height[stack.peek()] <= height[i]){
                stack.pop();
            }
            int sSize = stack.size();
            cnt[i] += sSize;
            if(sSize > 0 && stack.peek()-i < i - near[i]) near[i] = stack.peek();
            stack.push(i);
        }    

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            sb.append(cnt[i]);
            if(cnt[i] > 0) sb.append(" ").append(near[i]+1);
            sb.append("\n");
        }

        bw.append(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }
}