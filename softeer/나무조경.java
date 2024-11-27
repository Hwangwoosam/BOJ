import java.util.*;
import java.io.*;

class Main{
    static int n,answer,cntLimit;
    static int map[][];
    static boolean visited[][];
    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,1,-1};

    static void findAnswer(int cnt, int result){
        if(cnt == cntLimit){
            answer = Math.max(answer, result);
            return;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                visited[i][j] = true;
                
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    findAnswer(cnt+1, result + map[i][j] + map[nx][ny]);
                    visited[nx][ny] = false;
                }

                visited[i][j] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        answer = 0;
        cntLimit = 4;

        n = Integer.parseInt(br.readLine());
        
        if(n == 2) cntLimit = 2;
        map = new int[n][n];
        visited = new boolean[n][n];

        for(int i = 0; i < n; i++){
            String[] inp = br.readLine().split(" ");
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(inp[j]);
            }
        }

        findAnswer(0,0);

        bw.append(answer + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}