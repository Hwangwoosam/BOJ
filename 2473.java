import java.util.*;
import java.io.*;

class Main{

    //x y z = k
    //x y k-(x+z)
    static int n; 
    static long ans = Long.MAX_VALUE;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        Long arr[] = new Long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(arr);
        int start, left, right;
        int ansLeft=0,ansMid=0,ansRight=0;

        for(int i = 0; i < n; i++){
            start = i;
            left = i+1;
            right = n-1;
            boolean done = false;
            while(left < right){
                long sum = arr[start] + arr[left] + arr[right];

                if(Math.abs(ans) > Math.abs(sum)){
                    ans = sum;
                    ansLeft = start;
                    ansMid = left;
                    ansRight = right;

                    if(sum == 0){
                        done = true;
                        break;
                    }
                }

                if(sum > 0){
                    right--;
                }else{
                    left++;
                }
            }

            if(done) break;
        }

        System.out.println(arr[ansLeft] + " " + arr[ansMid] + " " + arr[ansRight]);
    }
}