import java.io.*;
import java.util.*;

class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n,m;

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            map.put(br.readLine(),0);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(map.containsKey(br.readLine())) cnt++;
        }
        
        bw.append(cnt + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}