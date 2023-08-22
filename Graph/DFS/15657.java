package Graph.DFS;
import java.util.*;
import java.io.*;

public class Main{
    static int n,m;
    static int[] arr, printArr;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        arr = new int[n];
        printArr = new int[m];

        for(int i=0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(arr);
        
        dfs(0,0);
    }

    static void dfs(int startIdx, int depth){
        if(depth == m){
            for(int i = 0; i < m; i++){
                System.out.print(printArr[i] + " ");
            }
            System.out.println();
            return;
        }

        for(int i = startIdx; i <n; i++){
            printArr[depth] = arr[i];
            dfs(i,depth+1);
        }
    }
}