import java.util.*;
import java.io.*;

class Main{
    static long n;
    static int cnt = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Long.parseLong(br.readLine());
        long tmp = n;

        for(long i = 2; i*i <= tmp; i++){
            while(tmp%i == 0){
                tmp /= i;
                cnt++;
            }

        }


        if(tmp > 1) cnt++;

        if(cnt == 2) System.out.println("cubelover");
        else System.out.println("koosaga");
    }
}