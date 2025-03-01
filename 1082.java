import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] price;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        price = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++){
            price[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());

        int[] ans = new int[100];
        int cost = 0;
        int idx = 0;
        
        int minIdx = findMin(0);
        if(minIdx == 0){
            minIdx = findMin(1);
            if(price[minIdx] <= m){
                ans[idx++] = minIdx;
                cost += price[minIdx];
                minIdx = 0;
            }else{
                System.out.println(0);
                return;
            }
        }

        while(cost + price[minIdx] <= m){
            ans[idx++] = minIdx;
            cost += price[minIdx];
        }

        for(int i = 0; i < idx; i++){
            for(int j = n-1; j >= 0; j--){
                if(cost - price[ans[i]] + price[j] <= m){
                    cost = cost - price[ans[i]] + price[j];
                    ans[i] = j;
                    break;
                }
            }
        }

        for(int i = 0; i < idx; i++){
            System.out.print(ans[i]);
        }
    }

    static int findMin(int start){
        int minValue = 100;
        int idx = 0;
        for(int i = start; i < n; i++){
            if(minValue > price[i]){
                minValue  = price[i];
                idx = i;
            }
        }

        return idx;
    }

}