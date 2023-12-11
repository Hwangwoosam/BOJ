import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
    public static int n;
    public static boolean[] num = new boolean[1003002];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        getPrime();

        for(int i = n; i <= 1003001; i++){
            if(num[i] && checkPelin(i)){
                System.out.println(i);
                break;
            }
        }
    }

    public static void getPrime(){
        for(int i = 2; i <= 1003001; i++){
            num[i] = true;
        }

        int maxLimit = (int)Math.sqrt(1003001);

        for(int i=2; i <= maxLimit; i++){
            if(num[i]){
                for(int j=i; i*j <= 1003001; j++){
                    num[i*j] = false;
                }
            }
        }
    }

    public static boolean checkPelin(int i){
        StringBuffer numStr = new StringBuffer(String.valueOf(i));
        // System.out.println(numStr.toString() + " " + numStr.reverse().toString());
        if(numStr.toString().equals(numStr.reverse().toString())){
            return true;
        }

        return false;
    }
}