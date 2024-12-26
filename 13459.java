import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static char[][] map;
    static Pair red,blue,hole;
    static int[] dx = {1,0,-1,0};
    static int[] dy=  {0,1,0,-1};
    static boolean[][][][] visited;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        map = new char[n][m];
        visited = new boolean [n][m][n][m];

        for(int i = 0; i < n; i++) {
            map[i] = br.readLine().toCharArray();
            for(int j = 0; j < m; j++){
                if(map[i][j] == '#' || map[i][j] == '.' || map[i][j] == 'O') continue;

                if(map[i][j] == 'R')red = new Pair(i,j,0);
                else if(map[i][j] == 'B') blue = new Pair(i,j,0);
            }
        }

        bw.append(bfs() + "\n");
        bw.flush();
    }

    static int bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(red);
        q.add(blue);

        while(!q.isEmpty()){
            Pair rCur = q.poll();
            Pair bCur = q.poll();
            // System.out.println("Cur Red: " + rCur.x + " " + rCur.y);
            // System.out.println("Cur blue: " + bCur.x + " " + bCur.y);
            if(bCur.cnt >= 10) break;

            for(int i = 0; i < 4; i++){
                int mrlen = move(rCur.x,rCur.y,i);
                int mblen = move(bCur.x,bCur.y,i);
                int rnx = rCur.x + dx[i] * mrlen;
                int rny = rCur.y + dy[i] * mrlen;
                int bnx = bCur.x + dx[i] * mblen;
                int bny = bCur.y + dy[i] * mblen;

                // System.out.println("Red: " + rnx + " " + rny);
                // System.out.println("Blue: " + bnx + " " + bny);
                if(map[bnx][bny] == 'O') continue;
                else if(map[rnx][rny] == 'O'){
                    return 1;
                }else{
                    if(bnx == rnx && bny == rny){
                        if(mrlen > mblen){
                            rnx -= dx[i];
                            rny -= dy[i];
                        }else{
                            bnx -= dx[i];
                            bny -= dy[i];
                        }
                    }

                    if(visited[rnx][rny][bnx][bny] == false){
                        visited[rnx][rny][bnx][bny] = true;
                        q.add(new Pair(rnx,rny,rCur.cnt+1));
                        q.add(new Pair(bnx,bny,bCur.cnt+1));
                    }
                }
            }
        }

        return 0;
    }

    static int move(int x, int y, int dir) {
    int moveLen = 0;
    while(true) {
        x += dx[dir];
        y += dy[dir];
        moveLen++;
        if(map[x][y] == '#') {
            return moveLen - 1;
        }
        if(map[x][y] == 'O') {
            return moveLen;
        }
    }
}


    static class Pair{
        int x;
        int y;
        int cnt;

        Pair(int x,int y,int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}