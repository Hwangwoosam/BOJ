import java.io.*;
import java.util.*;

class Main{
    static boolean[] check;
    static int n;
    static int[] arr;
    static Set<String> ans;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        n = Integer.parseInt(br.readLine());
        check = new boolean[n+1];
        arr = new int[n+1];
        List<Integer> st = new LinkedList<>();
        String res = "";
        findAnswer(1,0);
        bw.write(sb.toString());
        bw.flush();

        br.close();
        bw.close();
    }

    static void findAnswer(int depth,int next) {
        if(depth == n+1) {
            for(int i = 1; i <= n; i++){
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            // System.out.println(res);
            return;
        }

        for(int i = 1; i <= n; i++) {
            if(check[i]) continue;
            if(i > arr[depth-1] && i < next) break;
            
            arr[depth] = i;
            check[i] = true;
            if(i >= next){
                findAnswer(depth+1,i+1);
            }else{
                findAnswer(depth+1,next);
            }
            check[i] = false;
        }
    }
}