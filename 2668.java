import java.util.*;
import java.io.*;   

class Main{
    static int n;
    static int[] nums;
    static boolean[] visited;
    static ArrayList<Integer> cycle = new ArrayList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        nums = new int[n+1];
        visited = new boolean[n+1];

        for(int i = 1; i <= n; i++){
            nums[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 1; i <= n; i++){
            visited[i] = true;
            dfs(i,i);
            visited[i] = false;
        }

        Collections.sort(cycle);
        System.out.println(cycle.size());
        for(int i = 0; i < cycle.size(); i++){
            System.out.println(cycle.get(i));
        }
    }  

    static void dfs(int idx, int target){
        if(visited[nums[idx]] == false){
            visited[nums[idx]] = true;
            dfs(nums[idx],target);
            visited[nums[idx]] = false;
        }

        if(nums[idx] == target) cycle.add(target);
    }
}