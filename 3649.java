import java.util.*;
import java.io.*;

class Main{
    static int t;
    static int MOD = 10000000;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        while(br.ready()){
            int x = Integer.parseInt(br.readLine());
            x *= MOD;
            int n = Integer.parseInt(br.readLine());

            int[] num = new int[n];
            for(int i = 0; i < n; i++) num[i] = Integer.parseInt(br.readLine());
            Arrays.sort(num);
            
            int left = 0, right = n-1;
            boolean find = false;
            while(left < right){
                // System.out.println(left + " " + right);
                int sum = (num[left] + num[right]);
                if(sum < x) left++;
                else if(sum > x) right--;
                else {
                    find = true;
                    sb.append("yes ").append(num[left]).append(" ").append(num[right]).append("\n");
                    break;
                }
            }
            if(!find) sb.append("danger\n");
        }
        System.out.print(sb.toString());
    }
}