import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            // System.out.println(a + " " + b);
            if(a == 0 && b == 0) break;

            int total = change_watt(a);
            int left = 0, right = total/2;
            while(left <= right){
                int mid = (left + right) / 2;
                // System.out.println(left + " " + mid + " " + right);
                int s_price = cal_price(mid);
                int n_price = cal_price(total-mid);

                int diff = Math.abs(s_price-n_price);
                // System.out.println("b:diff = " + b + " " + diff);
                if(diff < b){
                    right = mid-1;
                }else if(diff > b){
                    left = mid+1;
                }else{
                    System.out.println(s_price);
                    break;
                }
            }
        }
    }

    static int change_watt(int p){
        if(p <= 200) return p/2;
        else if(p <= 29900) return (p-200)/3 + 100;
        else if(p <= 4979900) return (p-29900)/5 + 10000;
        else return (p-4979900)/7 + 1000000;
    }

    static int cal_price(int watt){
        if(watt <= 100) return watt*2;
        else if(watt <= 10000) return 200 + (watt-100)*3;
        else if(watt <= 1000000) return 200 + 29700 + (watt-10000)*5;
        else return 200 + 29700 + 4950000 + (watt - 1000000) * 7;
    }
}