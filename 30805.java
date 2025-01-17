import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static int[] a,b;
    static Queue<Integer> ans = new LinkedList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        a = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) a[i] = Integer.parseInt(st.nextToken());

        m = Integer.parseInt(br.readLine());
        b = new int[m];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++) b[i] = Integer.parseInt(st.nextToken());

        int aIdx = 0, bIdx = 0;
        while(aIdx < n && bIdx < m){
            int res = 0;
            // System.out.println(aIdx + " " + bIdx);
            for(int i = aIdx; i < n; i++){
                for(int j = bIdx; j < m; j++){
                    // System.out.println("a b :" + a[i] + " " + b[j]);
                    if(a[i] == b[j]) res = Math.max(res,a[i]);
                }
            }

            // System.out.println("res: " + res);
            if(res != 0){
                ans.add(res);
                while(a[aIdx] != res) aIdx++;
                while(b[bIdx] != res) bIdx++;

                aIdx++;
                bIdx++;
            }else break;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append("\n");
        while(!ans.isEmpty()) sb.append(ans.poll()).append(" ");
        System.out.println(sb.toString());
    }
} 