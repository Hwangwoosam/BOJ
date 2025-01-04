import java.io.*;
import java.util.*;

class Main{

    static long[] f = new long[1000001];
    static long[] g = new long[1000001];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Arrays.fill(f,1);
        g[1] = 1;
        for(int i = 2; i <= 1000000; i++){
            for(int j = 1; j*i <= 1000000; j ++){
                f[i*j] += i;
            }
            g[i] = g[i-1] + f[i];
        }

        int t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            System.out.println(g[n]);
        }
    }
}