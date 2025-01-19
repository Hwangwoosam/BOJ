import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int[] num;
    static int[] numIdx;
    static int[] res;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        num = new int[n+1];
        res = new int[n+1];
        int maxLimit = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) maxLimit = Math.max(maxLimit,num[i] = Integer.parseInt(st.nextToken()));
        
        numIdx = new int[maxLimit+1];
        for(int i = 0; i < n; i++) numIdx[num[i]] = i+1;
        for(int i = 0; i < n; i++) {

            for(int j = num[i]*2; j <= maxLimit; j+= num[i]){
                if(numIdx[j] != 0){
                    res[numIdx[j]]--;
                    res[numIdx[num[i]]]++;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= n; i++) sb.append(res[i]).append(" ");

        System.out.println(sb.toString());
    }
}