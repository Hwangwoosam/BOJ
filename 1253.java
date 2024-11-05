import java.util.*;
import java.io.*;

class Main{

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] nums = new int[n];
        for(int i = 0; i < n; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }        

        Arrays.sort(nums);

        int cnt = 0;

        for(int i = 0; i < n; i++){
            int left = 0;
            int right = n-1;

            while(true){
                if(left == i) left++;
                else if(right == i) right--;

                if(left >= right) break;

                if(nums[left] + nums[right] > nums[i]) right--;
                else if (nums[left] + nums[right] < nums[i]) left++;
                else{
                    cnt++;
                    break;
                }
            }
        }

        bw.append(cnt + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}