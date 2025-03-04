import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int[] cards;
    static int[] oddSum;
    static int[] evenSum;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        cards = new int[n];
        oddSum = new int[n/2+1];
        evenSum = new int[n/2+1];
        oddSum[0] = 0;
        evenSum[0] = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            cards[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < n; i++){
            if((i+1)%2 == 0){
                evenSum[i/2+1] = cards[i] + evenSum[i/2];
            }else{
                oddSum[i/2+1] = cards[i] + oddSum[i/2];
            }
        }
        
        int max = 0;
        int[] res = new int[n+1];
        for(int i = 1; i <= n; i++){
            if(i%2 == 0){
                res[i] = oddSum[i/2] + (evenSum[n/2-1] - evenSum[i/2-1]);
            }else{
                res[i] = oddSum[i/2] + (evenSum[n/2-1] - evenSum[i/2]) + cards[n-1];
            }

            max = Math.max(max,res[i]);
        }

        System.out.println(max);
    }
}