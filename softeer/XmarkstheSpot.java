import java.util.*;
import java.io.*;

class Main{

    static int n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; i++){
            String inp[] = br.readLine().split(" ");
            int idx = inp[0].toUpperCase().indexOf('X');
            sb.append(inp[1].toUpperCase().charAt(idx));
        }

        sb.append("\n");
        
        bw.append(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }
}