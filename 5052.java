import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            
            String[] phoneNumbers = new String[n];
            for(int j = 0; j < n; j++){
                phoneNumbers[j] = br.readLine();
            }

            Arrays.sort(phoneNumbers);

            if(isRelate(phoneNumbers,n)){
                bw.append("YES\n");
            }else{
                bw.append("NO\n");
            }
        }

        bw.flush();
    }

    static boolean isRelate(String[] numbers,int s){

        for(int i = 1; i < s; i++){
            if(numbers[i].startsWith(numbers[i-1])){
                return false;
            }
        }


        return true;
    }
}