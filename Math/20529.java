import java.util.*;
import java.io.*;

public class Main {
    static int t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t= Integer.parseInt(br.readLine());
        
        for(int i = 0; i < t; i++){
            int n;
            n = Integer.parseInt(br.readLine());
            String []mbtis = br.readLine().split(" ");

            if(n > 32){
                bw.write("0");
                bw.write("\n");
                bw.flush();
            }else{
                bw.write(String.valueOf(getMinimum(n,mbtis)));
                bw.write("\n");
                bw.flush();
            }
        }
    }

    private static int getMinimum(int n,String[] str){
        int result = 1000;
        
        for(int i = 0; i <n; i++){
            for(int j = i+1; j < n; j++){
                for(int k =j+1; k < n; k++){
                    result = Math.min(result,getDistance(str[i],str[j])+getDistance(str[j], str[k])+getDistance(str[i], str[k]));
                }
            }
        }
        
        return result;
    }

    private static int getDistance(String a, String b){
        String[] aWord = a.split("");
        String[] bWord = b.split("");
        int dist = 0;
        for(int i = 0; i < 4; i++){
            if(!aWord[i].equals(bWord[i])){
                dist++;
            }
        }
        return dist;
    }
}
