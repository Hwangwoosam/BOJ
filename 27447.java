import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[] customers = new int [n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i ++){
            customers[i] = Integer.parseInt(st.nextToken());
        }

        int togi = 0;
        int coffee = 0;
        int servingIdx = 0;
        int customerIdx = 0;
        
        for(int i = 0; i <= customers[n-1]; i++){
            if(customers[servingIdx] == i){
                if(coffee > 0){
                    servingIdx++;
                    coffee--;
                }else{
                    System.out.println("fail");
                    return;
                }
            }else if(customerIdx < n && customers[customerIdx] <= i+m){
                if(togi ==0){
                    togi++;
                }else{
                    coffee++;
                    togi--;
                    customerIdx++;
                }
            }else{
                togi++;
            }
        }

        System.out.println("success"); 
    }
}