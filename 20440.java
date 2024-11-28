import java.io.*;
import java.util.*;

class Main{
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
    
        Map<Long,Integer> map = new HashMap<>();

        StringTokenizer st;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            long start = Long.parseLong(st.nextToken());
            long end = Long.parseLong(st.nextToken());

            if(!map.containsKey(start)) map.put(start,1);
            else map.replace(start,map.get(start)+1);
            

            if(!map.containsKey(end)) map.put(end,-1);
            else map.replace(end,map.get(end)-1);
        }

        List<Long> keySet = new ArrayList<>(map.keySet());

        Collections.sort(keySet);

        int ans = 0;
        int num = 0;
        int prevNum = 0;

        long stTime = 0;
        long endTime = 0;
        
        boolean rangeCheck = false;
        for(Long idx : keySet){
            prevNum = num;
            num += map.get(idx);

            if(rangeCheck && prevNum != num){
                endTime = idx;
                rangeCheck= false;
            }

            if(ans < num) {
                ans = num;
                stTime = idx;
                rangeCheck = true;
            }

        }

        bw.append(ans + "\n");
        bw.append(stTime + " " + endTime + "\n");
        bw.flush();
    }
}