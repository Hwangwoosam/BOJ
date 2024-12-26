import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static char[][] map;
    static boolean[][] visited;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++) map[i] = br.readLine().toCharArray();
        

        int cnt = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i,j)) cnt++;
            }
        }

        bw.append(cnt+"\n");
        bw.flush();
    }

    static boolean dfs(int x,int y){
        boolean res = false;

        if(x < 0 || x >=n || y < 0 || y >= m) return true;

        if(map[x][y] == 'T') return true;
        else if(map[x][y] == 'F') return false;

        if(visited[x][y]) return false;
        
        visited[x][y] = true;

        if(map[x][y] == 'U') res = dfs(x-1,y);
        else if(map[x][y] == 'R') res = dfs(x,y+1);
        else if(map[x][y] == 'L') res = dfs(x,y-1);
        else if(map[x][y] == 'D') res = dfs(x+1,y);

        map[x][y] = res ? 'T' : 'F';
        return res;
    }
}