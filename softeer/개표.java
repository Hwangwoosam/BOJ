import java.util.*;
import java.io.*;

class Main{
    static int t;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            int plus = n/5;
            int left = n%5;

            while(plus-- > 0){
                bw.append("++++ ");
            }

            while (left-- > 0) {
                bw.append("|");
            }

            bw.append("\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}