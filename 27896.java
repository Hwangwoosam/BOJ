import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] student;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        student = new int[n];

        st = new StringTokenizer(br.readLine());
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int val = Integer.parseInt(st.nextToken());
            q.add(val);
            sum += val;
            
            while(sum >= m){
                ans++;
                sum -= q.poll()*2;
            }
        }

        System.out.println(ans);
    }
}