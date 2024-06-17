import java.util.*;
import java.io.*;

class Main{
    static int n;
    static Deque<Node> now = new LinkedList<>();
    static Deque<Node> after = new LinkedList<>();
    static class Node{
        int idx;
        long val;

        Node(int idx, long val){
            this.idx = idx;
            this.val = val;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String inp[] = br.readLine().split(" ");
        for(int i = 0; i < n; i++){
            long val = Long.parseLong(inp[i]);

            now.add(new Node(i+1,val));
        }

        while(now.size()> 1){
            Node pre,cur,next;
            // bw.append("size: " + now.size() + " " + after.size() + "\n");

            while(!now.isEmpty()){
                if(!after.isEmpty()) pre = after.pollLast();
                else pre = new Node(0,0);

                cur = now.pollFirst();
                
                if(!now.isEmpty()) next = now.pollFirst();
                else next = new Node(0,0);

                // bw.append("pre: " + pre.val + "\n");
                // bw.append("cur: " + cur.val + "\n");
                // bw.append("next: " + next.val + "\n");
                // bw.flush();

                if(pre.idx != 0 && next.idx != 0 && pre.val <= cur.val && next.val <= cur.val){
                    after.addLast(new Node(cur.idx,pre.val + cur.val + next.val));
                    continue;
                }

                if(pre.idx != 0 && pre.val <= cur.val){
                    if(next.idx != 0) now.addFirst(next);
                    after.add(new Node(cur.idx,pre.val + cur.val));
                    continue;
                }

                if(next.idx != 0 && next.val <= cur.val){
                    if(pre.idx != 0) after.addLast(pre);
                    after.addLast(new Node(cur.idx,cur.val + next.val));
                    continue;
                }

                if(pre.idx != 0) after.addLast(pre);
                after.addLast(cur);
                if(next.idx != 0) now.addFirst(next);
            }

            now = after;
            after = new LinkedList<>();
        }
        
        bw.append(now.peek().val + "\n" + now.peek().idx + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}