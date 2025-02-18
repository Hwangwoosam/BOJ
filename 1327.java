import java.util.*;
import java.io.*;

class Main{
    static int n,k;
    static ArrayList<Integer> list = new ArrayList<>();
    static String num,ans;
    static Set<String> visited = new HashSet<>();

    static int bfs(String number){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(number,0));
        visited.add(number);

        while(!q.isEmpty()){
            Pair cur = q.poll();

            if(cur.s.equals(ans)) return cur.cnt;

            for(int i = 0 ; i <= (n-k); i++){
                char[] arr = cur.s.toCharArray();

                for(int j = 0; j < (k/2); j++){
                    char tmp = arr[i+j];
                    arr[i+j] = arr[i+k-1-j];
                    arr[i+k-1-j] = tmp;
                }

                String nextStr = new String(arr);

                if(!visited.contains(nextStr)){
                    Pair next = new Pair(nextStr,cur.cnt+1);
                    q.add(next);
                    visited.add(next.s);
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) sb.append(st.nextToken());
        num = sb.toString();
        sb.setLength(0);
        for(int i = 1; i <= n; i++) sb.append(i);
        ans = sb.toString();

        System.out.println(bfs(num));
    }

    static class Pair{
        String s;
        int cnt;
        
        Pair(String s, int cnt){
            this.s = s;
            this.cnt = cnt;
        }
    }
}