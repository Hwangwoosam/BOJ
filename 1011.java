import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++){
            st = new StringTokenizer(br.readLine());
            Long x = Long.parseLong(st.nextToken());
            Long y = Long.parseLong(st.nextToken());

            Long dist = y-x;
            Long maxVal = (long)Math.sqrt(dist);

            if(maxVal == Math.sqrt(dist)){
                bw.append(String.valueOf(2*maxVal - 1));
            }else if(dist <= maxVal*maxVal + maxVal){
                bw.append(String.valueOf(2*maxVal));
            }else{
                bw.append(String.valueOf(2*maxVal + 1));
            }

            bw.append("\n");
            bw.flush();
        }

    }
}