import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        boolean check[] = new boolean[50];

        String inp = br.readLine();
        int inpSize = inp.length();
        for(int i = 1; i < n; i++){
            String tmp = br.readLine();
            for(int j = 0; j < inpSize; j++){
                if(check[j]) continue;
                if(inp.charAt(j) != tmp.charAt(j)) check[j] = true;
            }
        }

        for(int i = 0; i < inpSize; i++){
            if(!check[i]) bw.append(inp.charAt(i));
            else{
                bw.append('?');
            }
        }
        bw.append("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}