import java.util.*;
import java.io.*;

class Main{
    static int n;
    static PriorityQueue<Meeting> pq = new PriorityQueue<>();
    static PriorityQueue<Long> curMeeting = new PriorityQueue<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            Long start = Long.parseLong(st.nextToken());
            Long end = Long.parseLong(st.nextToken());
            pq.add(new Meeting(start,end));
        }

        while(!pq.isEmpty()){
            Meeting cur = pq.poll();
            
            if(!curMeeting.isEmpty() && curMeeting.peek() <= cur.start){
                curMeeting.poll();
            }

            curMeeting.add(cur.end);
        }

        System.out.println(curMeeting.size());
    }

    static class Meeting implements Comparable<Meeting>{
        Long start;
        Long end;
        Meeting(Long start, Long end){
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Meeting o){
            int cmp = this.start.compareTo(o.start);

            if(cmp == 0){
                return this.end.compareTo(o.end);
            }

            return cmp;
        }
    }
}