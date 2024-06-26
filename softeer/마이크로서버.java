import java.util.*;
import java.io.*;

class Main{
    static int t;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t ;i++){
            int n = Integer.parseInt(br.readLine());
            
            int[] service = new int[n];

            String inp[] = br.readLine().split(" ");
            
            for(int j = 0; j < n; j++) service[j] = Integer.parseInt(inp[j]);
            Arrays.sort(service);
            
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(service[j] != 300) break;
                cnt++;
            }
            int start = cnt;
            int end = n-1;
            int result = 0;
            while(start <= end){
                if(service[end] > 600){ // 600 초과
                    result++;
                    end--;
                }
                else if(start != end){ //아래부터는 300 < w < 600
                    if(service[start] + service[end] <= 900){
                        result++;
                        start++;
                        end--;
                    }else if(cnt > 0){ // 300인 곳과 합침
                        result++;
                        end--;
                        cnt--;
                    }else{
                        result++;
                        end--;
                    }
                }
                else if(start == end){
                    if(cnt > 0){
                        result++;
                        end--;
                        cnt--;
                    }else{
                        result++;
                        end--;
                    }
                }
            }

            result += (cnt/3);
            if(cnt % 3 != 0) result++;
            bw.append(result+"\n");
            bw.flush();
        }

        br.close();
        bw.close();
    }
}