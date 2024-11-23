import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            char[] inp = br.readLine().toCharArray();
            int lastIdx = inp.length-1;
            int top = lastIdx;

            while(top > 0 && inp[top-1] >= inp[top]){
                top--;
            }

            if(top > 0){
                int pos = lastIdx;
                while(inp[top-1] >= inp[pos]) pos--;

                swap(inp,top-1,pos);

                while(top < lastIdx){
                    swap(inp,top,lastIdx);
                    top++;
                    lastIdx--;
                }
            }

            for(char c: inp) sb.append(c);

            sb.append("\n");
        }

        bw.append(sb.toString());
        bw.flush();
    }

    public static void swap(char[] input, int i, int j){
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}