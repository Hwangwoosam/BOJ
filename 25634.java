import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int[] bulb;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());

        bulb = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            bulb[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int lightOnSum = 0;
        int lightOffSum =  0;
        int max = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++){
            int bulbState = Integer.parseInt(st.nextToken());
            if(bulbState == 1){
                lightOnSum += bulb[i];
                lightOffSum -= bulb[i];
                if(max < -1*bulb[i]) max = -1*bulb[i]; 
            }else{
                lightOffSum += bulb[i];
                if(lightOffSum < bulb[i]) lightOffSum = bulb[i];
                if(max < lightOffSum) max = lightOffSum;
            }
        }

        System.out.println(lightOnSum + max);
    }
}