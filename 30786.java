import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
        int n = Integer.parseInt(br.readLine());
        
        List<Integer> num[] = new ArrayList[2];
        for(int i = 0; i < 2; i++){
            num[i] = new ArrayList<Integer>();
        }

        StringTokenizer st;
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            num[(x+y)%2].add(i);
        }

        if(num[0].size() == 0 || num[1].size() == 0){
            bw.append("NO");
        }else{
            bw.append("YES\n");
            for(int i = 0; i < 2; i++){
                for(int j : num[i]){
                    bw.append(j + " ");
                }
            }
        }
        bw.append("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
