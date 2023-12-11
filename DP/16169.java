import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;
import java.nio.Buffer;

class Main{
    public static int n,maxLevel;
    public static Vector[] level;
    public static int[] time;
    public static int[] computer;
    public static int[] answer;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        level = new Vector[n+1];
        for(int i = 0; i <= n; i++){
            level[i] = new Vector<Integer>();
        }

        time = new int[n+1];
        computer = new int[n+1];
  
        for(int i = 1; i <= n; i++){
            String[] inp = br.readLine().split(" ");
            int idx = Integer.parseInt(inp[0]); 
            int t = Integer.parseInt(inp[1]); 

            if(maxLevel < idx) maxLevel = idx;
            
            computer[i] = idx; 
            time[i] = t; 
            level[idx].add(i); 
        }

        findTIme();
    }

    public static void findTIme(){
        for(int i = 2; i <= n; i++){
            calculateTime(i);
        }
        
        int answer = 0;
        for(int i = 0; i < level[maxLevel].size(); i++){
            int idx = (int)level[maxLevel].get(i);
            if(answer < time[idx]) answer = time[idx];
        }
        System.out.print(answer);
    }

    public static void calculateTime(int curLevel){
        for(int i = 0; i < level[curLevel].size(); i++){
            int nextIdx = (int)level[curLevel].get(i);
            int maxValue = 0;
            for(int j = 0; j < level[curLevel-1].size(); j++){
                int curIdx = (int)level[curLevel-1].get(j);
                int curTime = time[curIdx];
                int calTime = curTime + (int)Math.pow(nextIdx - curIdx, 2);
                if(maxValue < calTime ) maxValue = calTime; 
            }

            time[nextIdx] = time[nextIdx] + maxValue;
            // System.out.println(nextIdx + ": " + time[nextIdx]);
        }
    }
}