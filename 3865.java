import java.util.*;
import java.io.*;

class Main{
    static Map<String,ArrayList<String>> map;
    static Set<String> visited;
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t;

        map = new HashMap<>();
        visited = new HashSet<String>();
        
        while(true){
            map.clear();
            visited.clear();

            t = Integer.parseInt(br.readLine());

            if(t == 0) break;
            String target = "";
            for(int i = 0; i < t ;i++){
                String[] inp = br.readLine().split(":");
                String[] members = inp[1].substring(0,inp[1].length()-1).split(",");
                
                if(i == 0) target = inp[0];

                if(!map.containsKey(inp[0])){
                    map.put(inp[0],new ArrayList<>());
                }

                for(String name: members) map.get(inp[0]).add(name);
            }

            visited.add(target);
            int res = findNum(target,0);
            bw.append(res + "\n");
            bw.flush();
        }
    }

    static int findNum(String key, int cnt){
        if(map.containsKey(key)){
            for(String child : map.get(key)){
                if(visited.contains(child)) continue;

                visited.add(child);
                cnt += findNum(child,map.get(child) == null ? 1 : 0);
            }
        }

        return cnt;
    }
}