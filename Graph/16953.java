import java.util.*;
import java.io.*;

public class Main{

    static long a,b;
    static int cnt = 0;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        a = sc.nextLong();
        b = sc.nextLong();
        
        bfs();
    }

    public static int bfs(){
        Queue<Long> q = new LinkedList<>();
        q.add(a);

        while(!q.isEmpty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                long elem = q.poll();

                if(elem*2 <= b) q.add(2*elem);
                if(elem*10 + 1 <= b) q.add(elem*10 + 1);
            }
            cnt++;            
        }
        return -1;
    }
}

