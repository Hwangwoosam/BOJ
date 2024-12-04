import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        ArrayList<Subject> c = new ArrayList<>();
        int[][] ans = new int[k+1][n+1];
        for(int i = 0; i < k ; i++){
            st = new StringTokenizer(br.readLine());
            c.add(new Subject(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
        }

        for(int i = 1; i <= k; i++){
            int curTime = c.get(i-1).time;
            int curValue = c.get(i-1).value;
            for(int j = 1; j <= n; j++){
                if(curTime <= j){
                    ans[i][j] = Math.max(ans[i-1][j],ans[i-1][j-curTime] + curValue);
                }else{
                    ans[i][j] = ans[i-1][j];
                }
            }
        }

        bw.append(ans[k][n] + "\n");
        bw.flush();
    }

    static class Subject{
        int value;
        int time;
        
        Subject(int value,int time){
            this.value = value;
            this.time = time;
        }
    }
}