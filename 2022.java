import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double x,y,c;

        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Double.parseDouble(st.nextToken());
        y = Double.parseDouble(st.nextToken());
        c = Double.parseDouble(st.nextToken());


        double left = 0, right = Math.max(x,y);
        while(right-left >= 0.001){
            double width = (left+right)/2;
            double h1 = Math.sqrt(Math.pow(x,2) - Math.pow(width,2));
            double h2 = Math.sqrt(Math.pow(y,2) - Math.pow(width,2));

            double res = (h1*h2)/(h1+h2);

            if(res >= c) left = width;
            else right = width;
        } 
        System.out.println(String.format("%.3f", right));
    }
}