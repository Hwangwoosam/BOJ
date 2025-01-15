import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String a = br.readLine();
        String b = br.readLine();
        int aSize = a.length();
        int bSize = b.length();

        int[][] dp = new int [aSize+1][bSize+1];

        for(int i = 1; i <= aSize; i++){
            for(int j = 1; j <= bSize; j++){
                if(a.charAt(i-1) == b.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        StringBuilder res = new StringBuilder();
        int x = aSize, y = bSize;
        
        while(x > 0 && y > 0){
            if(dp[x][y] == dp[x][y-1]) y--;
            else if(dp[x][y] == dp[x-1][y]) x--;
            else{
                res.append(a.charAt(x-1));
                x--;
                y--;
            } 
        } 

        // for(int i = 0; i <= aSize; i++){
        //     for(int j = 0; j <= bSize; j++){
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        System.out.println(dp[aSize][bSize]);
        System.out.println(res.reverse().toString());
    }
}