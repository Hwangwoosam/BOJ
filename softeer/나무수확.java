import java.util.*;
import java.io.*;

class Main{
    static int n;
    static int map[][];
    static int dp[][];
    static int rdp[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        map = new int[n+2][n+2];
        dp = new int[n+2][n+2];
        rdp = new int[n+2][n+2];

        for(int i = 1; i <= n; i++){
            String inp[] = br.readLine().split(" ");
            for(int j = 1; j <= n; j++){
                map[i][j] = Integer.parseInt(inp[j-1]);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]) + map[i][j];
                rdp[n+1-i][n+1-j] = Math.max(rdp[n+2-i][n+1-j],rdp[n+1-i][n+2-j]) + map[n+1-i][n+1-j]; 
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         bw.append(dp[i][j]  + " ");
        //     }
        //     bw.append("\n");
        // }
        // bw.append("---------------\n");
        // bw.flush();
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         bw.append(rdp[i][j]  + " ");
        //     }
        //     bw.append("\n");
        // }

        int maxVal = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(maxVal < dp[i][j] + rdp[i][j]){
                    maxVal = dp[i][j] + rdp[i][j];
                }
            }
        }

        bw.append(maxVal + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}