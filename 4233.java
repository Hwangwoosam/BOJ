import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st;
        while(true){
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long p = Long.parseLong(st.nextToken());

            if(a == 0 && p == 0) break;

            if(a > p){
                Long tmp = a;
                a = p;
                p = tmp;
            }
            
            if(isPrime(p)){
                System.out.println("no");
            }else{
                if(fpow(a,p,p) == a) System.out.println("yes");
                else System.out.println("no");
            }
        }
    }

    static boolean isPrime(long num){
        if(num < 2) return false;
        for(long i = 2; i*i <= num; i++){
            if(num%i == 0) return false;
        }

        return true;
    }

    static long fpow(long a, long p, long mod){
        if(p == 1){
            return a;
        }else{
            long x = fpow(a,(long)(p/2),mod);

            if((p%2) == 0){
                return (x*x)%mod;
            }else{
                return ((x*x)%mod*a)%mod;
            }
        }
    }
}