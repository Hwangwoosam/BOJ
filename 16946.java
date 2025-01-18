import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static char[][] map;
    static int[][] group;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static HashMap<Integer,Integer> groupInfo = new HashMap<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        group = new int[n][m];

        for(int i = 0; i < n; i++) map[i] = br.readLine().toCharArray();
        
        int idx = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == '0' && group[i][j] == 0) {
                    groupInfo.put(idx,getCount(i,j,idx));
                    idx++;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sb.append(getAns(i,j));
            }
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }

    static int getCount(int x,int y, int idx){
        int cnt = 1;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));
        group[x][y] = idx;

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i = 0; i < 4; i++){
                int nx = dx[i] + cur.x;
                int ny = dy[i] + cur.y;

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[nx][ny] == '1') continue;
                if(group[nx][ny] != 0) continue;

                q.add(new Pair(nx,ny));
                group[nx][ny] = idx;
                cnt++;
            }
        }

        return cnt;
    }

    static int getAns(int x,int y){
        int sum =1;
        HashSet<Integer> hs = new HashSet<>();

        if(map[x][y] == '0') return 0 ;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == '1') continue;
            if(group[nx][ny] == 0) continue;
            
            hs.add(group[nx][ny]);
        }

        for(int idx : hs) sum += groupInfo.get(idx);

        return sum%10;
    }
    static class Pair{
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}