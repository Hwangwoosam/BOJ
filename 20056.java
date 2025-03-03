import java.util.*;
import java.io.*;

class Main{
    static class FireBall{
        int x;
        int y;
        int m;
        int d;
        int s;

        FireBall(int x,int y,int m, int d, int s){
            this.x = x;
            this.y = y;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }

    static int n,m,k;
    static int [] dx = {-1,-1,0,1,1,1,0,-1}; 
    static int [] dy = {0,1,1,1,0,-1,-1,-1};
    static ArrayList<FireBall>[][] map;
    static ArrayList<FireBall> fireballs = new ArrayList<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new ArrayList[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[i][j] = new ArrayList<>();
            }
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            fireballs.add(new FireBall(x-1,y-1,m,d,s));
        }

        for(int i = 0; i < k; i++){
            //1.이동
            fireMove();
            //2. 동일 칸일 경우
            afterMove();
        }

        int ans = 0;
        for(FireBall cur : fireballs){
            ans += cur.m;
        }

        System.out.println(ans);
    }

    static void fireMove(){
        for(FireBall cur : fireballs){
            int nx = (cur.x + n + dx[cur.d] * (cur.s % n)) % n;
            int ny = (cur.y + n + dy[cur.d] * (cur.s % n)) % n;
            cur.x = nx;
            cur.y = ny; 
            map[cur.x][cur.y].add(cur);
        }
    }

    static void afterMove(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int ballCnt = map[i][j].size();
                if(ballCnt < 2){
                    map[i][j].clear();
                    continue;
                }

                int mSum = 0, sSum = 0, oddCnt = 0, evenCnt = 0;
                for(FireBall cur : map[i][j]){
                    mSum += cur.m;
                    sSum += cur.s;

                    if(cur.d % 2 == 1){
                        oddCnt++;
                    }else{
                        evenCnt++;
                    }
                    fireballs.remove(cur);
                }

                map[i][j].clear();
                mSum /= 5;
                if(mSum == 0) continue;
                
                sSum /= ballCnt;
                if(oddCnt == ballCnt || evenCnt == ballCnt){
                    for(int k = 0; k < 8; k+=2){
                        fireballs.add(new FireBall(i,j,mSum,k,sSum));
                    }
                }else{
                    for(int k = 1; k < 8; k+=2){
                        fireballs.add(new FireBall(i,j,mSum,k,sSum));
                    }
                }
            }
        }
    }
}