import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        //g = cur*cur - past*past;

        Long g = Long.parseLong(br.readLine());

        Long past = 1L;
        Long cur = 2L;
        while(past < cur && cur.compareTo(100000L) == -1){
            Long val = (cur+past)*(cur-past);
            if(val > g){
                past++;
            }else{
                if(val.equals(g)){
                    sb.append(cur).append("\n");
                }
                cur++;
            }
        }
        if(sb.toString().isEmpty()){
            sb.append("-1\n");
        }

        bw.append(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }
}