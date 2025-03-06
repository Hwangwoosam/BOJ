import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static int [][] board;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        board = new int[n+1][m+1];
        boolean color = false;
        for(int i = 1; i <= n; i++){
            String inp = br.readLine();
            for(int j = 1; j <= m; j++){
                char c = inp.charAt(j-1);
                if(!color && c == 'W'){
                    board[i][j] = 1;
                }else if(color && c == 'B'){
                    board[i][j] = 1;
                }

                color = !color;
            }

            if(m%2 == 0){
                color = !color;
            }
        }

        for(int i =1; i <= n; i++){
            int preSum = board[i][1];
            for(int j = 2; j <= m; j++){
                preSum += board[i][j];
                board[i][j] = preSum;
            }
        }

        for(int i=1; i<=m;i++){
            int preSum = board[1][i];
            for(int j=2;j<=n;j++){
                preSum += board[j][i];
                board[j][i] = preSum;
            }
        }

        int minCnt = Integer.MAX_VALUE, maxCnt = Integer.MIN_VALUE;
        for(int i=k;i<=n;i++){
            for(int j=k;j<=m;j++){
                int cnt = board[i][j] - (board[i-k][j] + board[i][j-k] - board[i-k][j-k]);
                minCnt = Math.min(minCnt, cnt);	
                maxCnt = Math.max(maxCnt, cnt);	
            }
        }

        int ans = Math.min(minCnt, k*k-maxCnt);
        System.out.println(ans);
    }
}