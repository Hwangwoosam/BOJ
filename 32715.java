import java.util.*;
import java.io.*;

class Main{
    static int n,m,k;
    static int [][]map;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        k = Integer.parseInt(br.readLine());

        map = new int[n][m];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] rows = new int[n][m];
        int[][] cols = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    rows[i][j] = (i > 0 ? rows[i - 1][j] : 0) + 1;
                    cols[i][j] = (j > 0 ? cols[i][j - 1] : 0) + 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cols[i][j] >= k * 2 + 1 &&
                        i + k < n && j - k >= 0 && rows[i + k][j - k] >= k * 2 + 1) {
                    cnt++;
                }
            }
        }

        System.out.println(cnt);
    }

}