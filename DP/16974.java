import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;

class Main{
    public static int n = 0;
    public static long x = 0;
    public static long ans = 0;
    public static long[] burger = new long[51];
    public static long[] patty = new long[51];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        getInput(input);
        getNumber();
        
    }

    public static void getInput(String input){
        String[] str = input.split(" ");
        n = Integer.parseInt(str[0]);
        x = Long.parseLong(str[1]);
    }

    public static void getNumber(){
        burger[0] = 1;
        patty[0] = 1;
        for(int i = 0; i <= 49; i++){
            burger[i+1] = 2*burger[i] + 3;
            patty[i+1] = 2*patty[i] + 1;
            
        }

        solution(n,x);
    }

    public static void solution(int time, Long lower){
        if(lower == 0){
            System.out.print(ans);
            return;
        }else if(time == 0){
            ans++;
            System.out.print(ans);
            return;
        }
        lower--;

        if(lower.equals(burger[time-1])){
            ans += patty[time-1];
            lower -= burger[time-1];
            solution(time-1,lower);
        }else if (lower < burger[time-1]){
            solution(time-1,lower);
        }else if (lower > burger[time-1]){
            ans += patty[time-1]+1;
            lower -= (burger[time-1] + 1);
            solution(time-1,lower);
        }
    }
}