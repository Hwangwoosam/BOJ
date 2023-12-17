import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    static int n, answer = 0;
    static char[] pattern;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        pattern = br.readLine().toCharArray();
    
        getDay();

        System.out.println(answer);
    }

    public static void getDay(){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(pattern[i] == '('){
                cnt ++;
            }else{
                cnt --;
            }

            if(answer < Math.abs(cnt)) answer = Math.abs(cnt);
        }

        if(cnt != 0) answer = -1;
    }
}
