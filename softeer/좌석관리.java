import java.util.*;
import java.io.*;

class Main{
    static int n,m,q;

    static int map[][];
    static Pair userLocation[] = new Pair[10001];
    static int userState[] = new int[10001];
    static List<Pair> curSeat = new ArrayList<>();
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};

    static class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj){
            Pair t = (Pair)obj;
            return (this.x == t.x && this.y == t.y);
        }
    }

    static int getDist(int x,int y){
        int cSize = curSeat.size();
        int minVal = Integer.MAX_VALUE;
        for(int i = 0; i < cSize; i++){
            int curDist = (curSeat.get(i).x - x) * (curSeat.get(i).x - x) + (curSeat.get(i).y - y)*(curSeat.get(i).y - y);
            if(minVal > curDist) minVal = curDist;
        }

        return minVal;
    }

    static void setSeat(int x, int y){
        map[x][y]++;
        curSeat.add(new Pair(x,y));

        for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;

                map[nx][ny]++;
        }
    }

    static boolean findSeat(int id){
        int x = -1, y = -1;

        if(curSeat.isEmpty()){
            x = 1;
            y = 1;
        }else{
            int maxVal = Integer.MIN_VALUE;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(map[i][j] > 0) continue;
                    int curDist = getDist(i,j);
                    if(maxVal < curDist){
                        x = i;
                        y = j;
                        maxVal = curDist;
                    }
                }
            }
        }

        if(x == - 1 && y == -1){
            return false;
        }

        setSeat(x, y);
        userLocation[id] = new Pair(x,y);   
        userState[id] = 1;

        return true;
    }

    static void outSeat(int id){
        userState[id] = 2;
        int x = userLocation[id].x;
        int y = userLocation[id].y;
        
        map[x][y]--;
        curSeat.remove(new Pair(x,y));

        for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;

                map[nx][ny]--;
        }

        userLocation[id].x = 0;
        userLocation[id].y = 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
        String[] inp = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        m = Integer.parseInt(inp[1]);
        q = Integer.parseInt(inp[2]);

        map = new int[n+1][m+1];

        for(int i = 0; i < q; i++){
            inp = br.readLine().split(" ");
            int id = Integer.parseInt(inp[1]);

            if(inp[0].equals("In")){
                if(userState[id] == 0){
                    if(findSeat(id)){
                        bw.append(id + " gets the seat (" + userLocation[id].x + ", " + userLocation[id].y + ").\n");
                    }else{
                        bw.append("There are no more seats.\n");
                    }
                }else if(userState[id] == 1){
                    bw.append(id + " already seated.\n");
                }else if(userState[id] == 2){
                    bw.append(id + " already ate lunch.\n");
                }
            }else if(inp[0].equals("Out")){
                if(userState[id] == 0){
                    bw.append(id + " didn't eat lunch.\n");
                }else if(userState[id] == 1){
                    bw.append(id + " leaves from the seat ("+ userLocation[id].x + ", " + userLocation[id].y + ").\n");
                    outSeat(id);
                }else if(userState[id] == 2){
                    bw.append(id + " already left seat.\n");
                }
            }
            bw.flush();
        }

        bw.close();
        br.close();
    }
}