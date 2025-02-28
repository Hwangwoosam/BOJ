import java.util.*;
import java.io.*;

class Main{
    static int n;
    static PriorityQueue<Integer> left = new PriorityQueue<>(Comparator.reverseOrder());
    static PriorityQueue<Integer> right = new PriorityQueue<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        

        StringTokenizer st;
        long ans = 0;
        int curLoc = 0;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());

            if(op == 1){
                int loc = Integer.parseInt(st.nextToken());
                if(loc >= curLoc){
                    right.add(loc);
                }else{
                    left.add(loc);
                }
            }else if(op == 2){
                while(!(left.isEmpty() && right.isEmpty())){
                    if(left.isEmpty() || (!right.isEmpty() && curLoc - left.peek() > right.peek() - curLoc)){
                        ans += right.peek() - curLoc;
                        curLoc = right.poll();
                    }else{
                        ans += curLoc - left.peek();
                        curLoc = left.poll(); 
                    }
                }
            }
        }
        System.out.println(ans);
    }
}