import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.Buffer;


public class Main{
    static int n;
    public static void main(String[] args) throws IOException{
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(bf.readLine());

        if(n == 0){
            System.out.println("0");
            return;
        }

        int[] score = new int[n];

        for(int i = 0; i < n; i++){
            score[i] = Integer.parseInt(bf.readLine());
        }

        int excludeRange = (int)Math.round(n*0.15);
        Arrays.sort(score);
        
        bw.write(String.valueOf(getAverage(score,excludeRange)));
        bw.flush();
        bw.close();
    }

    public static int getAverage(int[] numList, int range){
        double sum = 0;
        for(int i = range; i < n-range; i++){
            sum += numList[i];
        }

        return (int)Math.round(sum/(n-2*range));
    }
}