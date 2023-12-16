import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int a,b,answer= 0;
    static boolean[] prime;
    static int[] count;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        a = Integer.parseInt(inp[0]);
        b = Integer.parseInt(inp[1]);

        prime = new boolean[b+1];
        count = new int[b+1];

        Arrays.fill(prime, true);
        getPrime();

        for(int i = a; i <= b; i++){
            if(prime[count[i]]) {
                answer ++;
            }
        }

        System.out.println(answer);
    }

    public static void getPrime(){
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i <= b; i++){
            if(!prime[i]) continue;
            for(int j = 2*i ; j <= b; j += i){
                prime[j] = false;
                int tmp = j;

                while(tmp%i == 0){
                    tmp /= i;
                    count[j]++;
                }
            }
        }
    }
    
}
