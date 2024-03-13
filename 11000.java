import java.io.*;
import java.util.*;

class Lecture{
    int start;
    int end;

    Lecture(int start,int end){
        this.start = start;
        this.end = end;
    }
}

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st; 
        Lecture[] lectures = new Lecture[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            lectures[i] = new Lecture(start,end);
        }
        
        Arrays.sort(lectures,(a,b) -> a.start == b.start ? a.end - b.end : a.start - b.start);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(lectures[0].end);

        for(int i = 1; i < n; i++){
            if(pq.peek() <= lectures[i].start){
                pq.poll();
            }

            pq.offer(lectures[i].end);
        }

        bw.write(pq.size() + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}