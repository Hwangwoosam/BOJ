import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        
        int[] schedule = new int[m+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= m; i++){
            schedule[i] = Integer.parseInt(st.nextToken());
        }

        String op = br.readLine();

        boolean flag = true;
        TreeMap<Integer,Integer> map = new TreeMap<>();
        ArrayList<String> visited = new ArrayList<>();
        visited.add("");

        int res = 1;
        for(int i = 0; i < m; i++){
            char dir = op.charAt(i);

            if(!map.containsKey(schedule[i])){
                if(dir == '+') map.put(schedule[i],1);
                else map.put(schedule[i],-1);
            }else{
                if(dir == '+') map.put(schedule[i],map.get(schedule[i]) + 1);
                else map.put(schedule[i], map.get(schedule[i]) - 1);
            }

            String cur = "";

            for(int key : map.keySet()){
                int val = map.get(key);
                if(val != 0){
                    cur += dist(key) + " " + dist(val) + " ";
                }
            }

            for(String str : visited){
                if(str.equals(cur)){
                    flag = false;
                    break;
                }
            }

            if(!flag){
                res = 0;
                break;
            }

            visited.add(cur);
        }
        bw.append(res + "\n");
        bw.flush();
    }

    static String dist(int val){
        String res = "";
        if(val < 0){
            res += "-";
            val *= -1;
        }

        int valCopy = val;
        int div = 0;
        while(valCopy > 1){
            valCopy /= 10;
            div++;
        }

        for(int i = div; i >= 0; i--){
            res += (char) (valCopy /Math.pow(10,i) + '0');
            valCopy %= Math.pow(10,i);
        }

        return res;
    }
}