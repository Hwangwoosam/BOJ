import java.util.*;
import java.io.*;

class Main{
    static int d,p;
    static int[] pipeLen = new int[100001];
    static Pipe[] pipes;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        d = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        pipes = new Pipe[p];

        for(int i = 0; i < p; i++){
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pipes[i] = new Pipe(l,c);
        }

        Arrays.sort(pipes);
        pipeLen[0] = Integer.MAX_VALUE;

        for(int i = 0; i < p; i++){
            for(int j = d; j >= pipes[i].len; j--){
                pipeLen[j] = Math.max(pipeLen[j],Math.min(pipeLen[j-pipes[i].len],pipes[i].capacity));
            }
        }
        System.out.println(pipeLen[d]);
    }

    static class Pipe implements Comparable<Pipe>{
        int len;
        int capacity;

        Pipe(int len,int capacity){
            this.len = len;
            this.capacity = capacity;
        }

        @Override
        public int compareTo(Pipe o){
            return this.len - o.len;
        }
    }
}