import java.util.*;
import java.io.*;

class Main{
    static int n;   
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        int cnt = 0;

        int left = 1, right = n;
        int val = 0;
        while(cnt < 20){
            int mid = (left + right) / 2;
            System.out.println("? "+mid);
            val = Integer.parseInt(br.readLine());
            if(val == mid - val){
                System.out.println("! " + mid);
                System.out.flush();
                System.exit(0);
            }else if( val < mid-val){
                right = mid-1;
            }else if( val > mid-val){
                left = mid+1;
            }

            cnt++;
        }

        System.out.println("! 0");
        System.out.flush();
    }
}