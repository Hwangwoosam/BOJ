import java.util.*;
import java.io.*;

class Main{ 
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String inp = br.readLine();

        int leftCnt = 0, rightCnt = 0;
        int sum = 0;

        for(int i = 0; i < inp.length(); i++){
            if(inp.charAt(i) == '('){
                leftCnt++;
                sum++;
            }else if(inp.charAt(i) == ')'){
                rightCnt++;
                sum--;
            }

            if(sum < 0){
                System.out.println(rightCnt);
                return;
            }else if(sum == 0){
                leftCnt = 0;
            }
        }

        System.out.println(leftCnt);
    }
}