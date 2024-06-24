import java.io.*;
import java.util.*;

class Main{
    static int n,t;
    static int[][][] map;
    static boolean[][][][] visited;
    static String signal[] = new String[13];
    static int dx[] = {-1,0,1,0}; // 위 오른 아래 왼
    static int dy[] = {0,1,0,-1};

    static class Car{
        int x;
        int y;
        int d;

        Car(int x,int  y, int d){
            this.x = x;
            this.y = y;
            this.d = d;
        }

        @Override
        public int hashCode(){
            return Objects.hash(this.x,
            this.y,
            this.d);
        }

        @Override
        public boolean equals(Object o){
            if(!(o instanceof Car)) return false;

            Car m = (Car) o;
            return (m.x == this.x &&
                    m.y == this.y &&
                    m.d == this.d                
            );
        }
    }

    static void setSignal(){
        signal[0] = "";
        signal[1] = "102";
        signal[2] = "013";
        signal[3] = "302";
        signal[4] = "213";
        signal[5] = "10";
        signal[6] = "03";
        signal[7] = "32";
        signal[8] = "21";
        signal[9] = "12";
        signal[10] = "01";
        signal[11] = "30";
        signal[12] = "23";
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        setSignal();

        String inp[] = br.readLine().split(" ");
        n = Integer.parseInt(inp[0]);
        t = Integer.parseInt(inp[1]);
        
        map = new int[n][n][4];
        visited = new boolean[n][n][4][4];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                inp = br.readLine().split(" ");
                for(int k = 0; k < 4; k++){
                    map[i][j][k] = Integer.parseInt(inp[k]);
                }
            }
        }
        
        Set<Car> answer = new HashSet<>();
        int time = 0;
        Queue<Car> q = new ArrayDeque();
        q.add(new Car(0,0,0));
        visited[0][0][0][0] = true;
        answer.add(new Car(0, 0, 0));

        while (!q.isEmpty()) {
            if(time == t) break;
            int curTime = q.size();
            
            for(int j = curTime; j > 0; j--){
                Car car = q.peek();
                q.poll(); 

                int preSignal = map[car.x][car.y][time%4];
                if(Character.getNumericValue(signal[preSignal].charAt(0)) != car.d) continue;

                for(int i = 0; i < signal[preSignal].length(); i++){
                    int signalIdx = Character.getNumericValue(signal[preSignal].charAt(i));
                    int nx = car.x + dx[signalIdx];
                    int ny = car.y + dy[signalIdx];
                
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[nx][ny][time%4][signalIdx]) continue;
                    visited[nx][ny][time%4][signalIdx] = true;
                    q.add(new Car(nx,ny,signalIdx));
                    answer.add(new Car(nx,ny,0));
                }
            }
            time++;
        }

        bw.append(answer.size() + "\n");
        bw.flush(); 
        br.close();
        bw.close();
    }
}