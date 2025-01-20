import java.util.*;
import java.io.*;

class Main{
    static int n,q;
    static int[] numCnt;
    static int[] nums;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        
        nums = new int[n+1];
        numCnt = new int[10001];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            int val = Integer.parseInt(st.nextToken());
            nums[i] = val;
            numCnt[val]++;
        }

        for(int i = 0; i < q; i++){
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            if(cmd == 1){
                boolean flag = false;
                if(val == 0){
                    if(val == 0){
                        if(numCnt[0] > 1 || (numCnt[0] > 0 && n - numCnt[0] > 0)) flag = true;
                    }
                }else{
                    for(int j = 1; j*j <= val; j++){
                        if(val%j == 0 && val/j < 10001){
                            int a = j;
                            int b = val/j;
                            if(numCnt[a] > 0 && numCnt[b] > 0){
                                if(a == b && numCnt[a] > 1) {
                                    flag = true;
                                    break;
                                }
                                if(a != b) {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                    }
                }

                if(flag) System.out.println(1);
                else System.out.println(0);
            }else{
                numCnt[nums[val]]--;
                nums[val] = 0;
                numCnt[0]++;

            }
        }
    
    }
}