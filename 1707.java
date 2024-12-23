import java.util.*;
import java.io.*;

class Main{
    static ArrayList<Integer>[] graph;
    static int[] groupNum;
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int k = Integer.parseInt(br.readLine());

        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            graph = new ArrayList[v+1];
            groupNum = new int[v+1];

            for(int j = 0; j <= v; j++) graph[j] = new ArrayList<>();

            for(int j = 0; j < e; j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                graph[a].add(b);
                graph[b].add(a);
            }

            grouping(v,e);
        }

    }

    static void grouping(int v,int e) throws Exception{
        Queue<Integer> q = new LinkedList<Integer>();

        for(int i = 1; i <= v; i++){
            if(groupNum[i] == 0){
                q.add(i);
                groupNum[i] = 1;
            }

            while(!q.isEmpty()){
                int cur = q.poll();

                for(int j = 0; j < graph[cur].size(); j++){
                    if(groupNum[graph[cur].get(j)] == 0) q.add(graph[cur].get(j));
                    if(groupNum[graph[cur].get(j)] == groupNum[cur]){
                        System.out.println("NO");
                        return;
                    }

                    if(groupNum[cur] == 1 && groupNum[graph[cur].get(j)] == 0) groupNum[graph[cur].get(j)] = 2;
                    else if(groupNum[cur] == 2 && groupNum[graph[cur].get(j)] == 0) groupNum[graph[cur].get(j)] = 1;
                }
            }

        }

        System.out.println("YES");
    }
}