import java.util.*;
import java.io.*;

class Main{
    static long s,t;
    static HashSet<Long> set = new HashSet<>();
    static String[] op = {"*","+","-","/"};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        s = Long.parseLong(st.nextToken());
        t = Long.parseLong(st.nextToken());

        bfs();
    }

    static void bfs(){
        if(s == t){
            System.out.println(0);
            return;
        }

        Queue<Num> q = new LinkedList<>();
        q.add(new Num(s,""));
        set.add(s);

        while(!q.isEmpty()){
            Num cur = q.poll();
            
            if(cur.num == t){
                System.out.println(cur.history);
                return;
            }

            for(int i = 0 ; i < 4; i++){
                long next = cur.num;
                if(i == 0) next *= cur.num;
                else if(i == 1) next += cur.num;
                else if(i == 2) next -= cur.num;
                else if(next != 0 ) next /= cur.num;
                
                if(!set.contains(next)){
                    set.add(next);
                    q.add(new Num(next,cur.history + op[i]));
                }
            }
        }

        System.out.println(-1);
        return;
    }

    static class Num{
        long num;
        String history;

        Num(long num, String history){
            this.num = num;
            this.history = history;
        }
    }
}