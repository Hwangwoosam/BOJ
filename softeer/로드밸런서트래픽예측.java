import java.util.*;
import java.io.*;

class Main{
    static int n;
    static long k;
    static int indegree[];
    static ArrayList<Integer> child[];
    static long result[];
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inp[] = br.readLine().split(" ");

        n = Integer.parseInt(inp[0]);
        k = Long.parseLong(inp[1]);

        indegree = new int[n+1];
        result = new long[n+1];
        child = new ArrayList[n+1];

        for(int i = 1; i <= n; i++){
            child[i] = new ArrayList<Integer>();
            inp = br.readLine().split(" ");

            int p = Integer.parseInt(inp[0]);

            for(int j = 1; j <= p; j++){
                int nw = Integer.parseInt(inp[j]);
                indegree[nw]++;
                child[i].add(nw);
            }
        }

        findResult(1,k);

        for(int i = 1; i<= n; i++){
            bw.append(result[i] + " ");
        }
        bw.append("\n");
        bw.flush();
        br.close();
        bw.close();
    }

    static void findResult(int idx,long val){
        result[idx] += val;
        
        if(indegree[idx] > 1){
            indegree[idx]--;
            return;
        }
        
        long childNum = child[idx].size();

        if(childNum > 0){
            long nVal = result[idx] / childNum;
            long left = result[idx] % childNum;

            for(int i = 0; i < childNum; i++){
                if(left > 0){
                    left--;
                    findResult(child[idx].get(i),nVal + 1);
                }else{
                    findResult(child[idx].get(i),nVal);
                }
            }
        }
    }
}