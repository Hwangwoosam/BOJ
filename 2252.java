import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Queue;

class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inp[] = br.readLine().split(" ");
        int n = Integer.parseInt(inp[0]);
        int m = Integer.parseInt(inp[1]);
        
        int indegree[] = new int[n+1];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n+1);
        for(int i = 0; i <= n; i++){ 
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++){
            String tmp[] = br.readLine().split(" ");
            int from = Integer.parseInt(tmp[0]);
            int to =Integer.parseInt(tmp[1]);

            adj.get(from).add(to);
            indegree[to]++;
        }

        Queue<Integer> q = new LinkedList<Integer>();
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            System.out.print(q.peek() + " ");
            int cur = q.poll();
                    
            if(!adj.get(cur).isEmpty()){
                for(int i = 0; i < adj.get(cur).size(); i++){
                    int next = adj.get(cur).get(i);
                    indegree[next]--;
                    if(indegree[next] == 0){
                        q.add(next);
                    }
                }
            }
        }
        System.out.println();
    }
}